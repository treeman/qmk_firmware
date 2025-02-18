/* Copyright 2021 Andrew Rae ajrae.nv@gmail.com @andrewjrae
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "casemodes.h"
#include "status.h"
#include "keycodes.h"

/* The caps word concept started with @iaap on splitkb.com discord.
 * However it has been implemented and extended by many splitkb.com users:
 * - @theol0403 made many improvements to initial implementation
 * - @precondition used caps lock rather than shifting
 * - @dnaq his own implementation which also used caps lock
 * - @sevanteri added underscores on spaces
 * - @metheon extended on @sevanteri's work and added specific modes for
 *   snake_case and SCREAMING_SNAKE_CASE
 * - @baffalop came up with the idea for xcase, which he implements in his own
 *   repo, however this is implemented by @iaap with support also for one-shot-shift.
 * - @sevanteri
 *     - fixed xcase waiting mode to allow more modified keys and keys from other layers.
 *     - Added @baffalop's separator defaulting on first keypress, with a
 *       configurable default separator and overrideable function to determine
 *       if the default should be used.
 */

#ifndef DEFAULT_XCASE_SEPARATOR
#    define DEFAULT_XCASE_SEPARATOR KC_UNDS
#endif

#define IS_OSM(keycode) (keycode >= QK_ONE_SHOT_MOD && keycode <= QK_ONE_SHOT_MOD_MAX)

// enum for the xcase states
enum xcase_state {
    XCASE_OFF = 0, // xcase is off
    XCASE_ON,      // xcase is actively on
    XCASE_WAIT,    // xcase is waiting for the delimiter input
};

// bool to keep track of the caps word state
static bool caps_word_on = false;

// enum to keep track of the xcase state
static enum xcase_state xcase_state = XCASE_OFF;
// the keycode of the xcase delimiter
static uint16_t xcase_delimiter;

// Check whether caps word is on
bool caps_word_enabled(void) {
    return caps_word_on;
}

bool is_caps_lock_on(void);
void tap_caps_lock(void);

// Enable caps word
void enable_caps_word(void) {
    if (!caps_word_on) {
        printf("Enable CAPSWORD\n");
    }
    caps_word_on = true;
    if (!is_caps_lock_on()) {
        tap_caps_lock();
    }
}

// Disable caps word
void disable_caps_word(void) {
    if (caps_word_on) {
        printf("Disable CAPSWORD\n");
    }
    caps_word_on = false;
    if (is_caps_lock_on()) {
        tap_caps_lock();
    }
}

// Toggle caps word
void toggle_caps_word(void) {
    if (caps_word_on) {
        disable_caps_word();
    } else {
        enable_caps_word();
    }
}

void process_caps_word_activation(const keyrecord_t *record) {
    if (!record->event.pressed) {
        return;
    }

    if (caps_word_enabled()) {
        printf("Set CAPS LOCK\n");
        caps_word_on = false;
    } else if (is_caps_lock_on()) {
        printf("Turn off CAPS LOCK\n");
        tap_code(is_caps_swapped() ? KC_ESC : KC_CAPS);
    } else {
        enable_caps_word();
    }
}

// Check whether xcase is on
bool xcase_enabled(void) {
    return xcase_state == XCASE_ON;
}

// Check whether xcase is waiting for a keypress
bool xcase_waiting(void) {
    return xcase_state == XCASE_WAIT;
}

// Enable xcase and pickup the next keystroke as the delimiter
void enable_xcase(void) {
    xcase_state = XCASE_WAIT;
}

// Enable xcase with the specified delimiter
void enable_xcase_with(uint16_t delimiter) {
    printf("Enable xcase with custom delimiter\n");
    xcase_state     = XCASE_ON;
    xcase_delimiter = delimiter;
}

// Disable xcase
void disable_xcase(void) {
    if (xcase_state != XCASE_OFF) {
        printf("Disable xcase\n");
    }
    xcase_state = XCASE_OFF;
}

// Place the current xcase delimiter
static void place_delimiter(void) {
    switch (xcase_delimiter) {
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX: {
            // apparently set_oneshot_mods() is dumb and doesn't deal with handedness for you
            uint8_t mods = xcase_delimiter & 0x10 ? (xcase_delimiter & 0x0F) << 4 : xcase_delimiter & 0xFF;
            set_oneshot_mods(mods);
            break;
        }
        default:
            tap_code16(xcase_delimiter);
            break;
    }
}

// overrideable function to determine whether the case mode should stop
__attribute__((weak)) bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

/* overrideable function to determine whether to use the default separator on
 * first keypress when waiting for the separator. */
__attribute__((weak)) bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t *record) {
    // for example:
    /* switch (keycode) { */
    /*     case KC_A ... KC_Z: */
    /*     case KC_1 ... KC_0: */
    /*         return true; */
    /* } */
    return false;
}

bool process_case_modes(uint16_t keycode, const keyrecord_t *record) {
    if (xcase_state == XCASE_WAIT) {
        // grab the next input to be the delimiter
        if (use_default_xcase_separator(keycode, record)) {
            enable_xcase_with(DEFAULT_XCASE_SEPARATOR);
        } else if (record->event.pressed) {
            if (keycode > QK_MODS_MAX || IS_MODIFIER_KEYCODE(keycode)) {
                // let special keys and normal modifiers go through
                return true;
            } else {
                // factor in mods
                if (get_mods() & MOD_MASK_SHIFT) {
                    keycode = LSFT(keycode);
                } else if (get_mods() & MOD_BIT(KC_RALT)) {
                    keycode = RALT(keycode);
                }
                enable_xcase_with(keycode);
                return false;
            }
            return false;
        } else {
            if (IS_OSM(keycode)) {
                // this catches the OSM release if no other key was pressed
                set_oneshot_mods(0);
                enable_xcase_with(keycode);
            }
            // let other special keys go through
            return true;
        }
    }

    if (caps_word_on || xcase_state) {
        if (record->event.pressed) {
            // check if the case modes have been terminated
            if (terminate_case_modes(keycode, record)) {
                disable_caps_word();
                disable_xcase();
                clear_oneshot_mods();
                reset_oneshot_layer();
            }
        }

        // Get the base keycode of a mod or layer tap key
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) return true;
                keycode = keycode & 0xFF;
                break;
            default:
                break;
        }

        if (record->event.pressed) {
            // handle xcase mode
            if (xcase_state == XCASE_ON) {
                // place the delimiter if needed
                if (keycode == XCASE_DELIMITER_KEY) {
                    place_delimiter();
                    return false;
                }
            }
        }

        return true;
    }
    return true;
}
