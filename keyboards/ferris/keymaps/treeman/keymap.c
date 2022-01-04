/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include <stdint.h>
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "status.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "roll.h"
#include "leader.h"

#include "keymap_swedish.h"
#include "sendstring_swedish.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: Modified RSTHD
    */
    [_BASE] = LAYOUT(
      SE_J,    SE_C,    SE_Y,    SE_F,    SE_P,         SE_X,    SE_W,    SE_O,    SE_U,    SE_DOT,
      SE_R,    SE_S,    SE_T,    SE_H,    SE_K,         SE_M,    SE_N,    SE_A,    SE_I,    REPEAT,
      SE_COMM, SE_V,    SE_G,    SE_D,    SE_B,         SE_SLSH, SE_L,    SE_LPRN, SE_RPRN, SE_UNDS,
                                 SHRT,    MT_SPC,       SE_E,    SPEC
    ),
    [_SWE] = LAYOUT(
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, SE_ARNG, SE_ADIA, SE_ODIA,
                                 _______, _______,      _______, _______
    ),
    [_NUM] = LAYOUT(
      SE_J,    SE_PLUS, SE_ASTR, SE_PERC, SE_P,         SE_X,    _______, _______, REPEAT,  _______,
      SE_6,    SE_4,    SE_0,    SE_2,    SE_K,         _______, SE_3,    SE_1,    SE_5,    SE_7,
      SE_COMM, _______, NUM_G,   SE_8,    _______,      _______, SE_9,    SE_LPRN, SE_RPRN, SE_UNDS,
                                 _______, _______,      CANCEL,  _______
    ),
    [_NAV] = LAYOUT(
      G(SE_J), C_TAB,   KC_UP,   KC_PGUP, KC_HOME,      xxxxxxx, G(SE_W), G(SE_E), G(SE_R), xxxxxxx,
      SC_TAB,  KC_LEFT, DN_CTRL, KC_RGHT, G(SE_K),      xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
      KC_ENT,  xxxxxxx, xxxxxxx, KC_PGDN, KC_END,       xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                 _______, _______,      WNAV,    _______
    ),
    // Important that the symbols on the base layer have the same positions as these symbols
    [_SYM] = LAYOUT(
      TILD,    SE_PLUS, SE_ASTR, SE_PERC, xxxxxxx,      xxxxxxx, SE_HASH, SE_AT,   CIRC,    SE_DOT,
      SE_PIPE, SE_LCBR, SE_RCBR, SE_MINS, SE_BSLS,      GRV,     SE_QUES, SE_LBRC, SE_RBRC, REPEAT,
      SE_COMM, SE_LABK, SE_RABK, SE_EXLM, xxxxxxx,      SE_SLSH, SE_AMPR, SE_LPRN, SE_RPRN, SE_UNDS,
                                 _______, _______,      CANCEL,  _______
    ),
    [_MODS] = LAYOUT(
      _______, _______, _______, _______, _______,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      _______, _______, _______, _______, _______,      xxxxxxx, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,
      _______, _______, _______, _______, _______,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MY_RALT,
                                 _______, _______,      _______,  _______
    ),
    [_SHRT] = LAYOUT(
      C(SE_A), C(SE_C), C(SE_W), C(SE_F), C(SE_E),      _______, _______, _______, _______, _______,
      C(SE_R), C(SE_S), C(SE_T), C(SE_H), xxxxxxx,      _______, _______, _______, _______, _______,
      C(SE_X), C(SE_V), C(SE_G), C(SE_D), C(SE_B),      _______, _______, _______, _______, _______,
                                 _______, _______,      _______, FUN
    ),
    [_WNAV] = LAYOUT(
      G(SE_J), G(SE_C), xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, G(SE_W), G(SE_E), G(SE_R), xxxxxxx,
      G(SE_6), G(SE_4), G(SE_0), G(SE_2), G(SE_K),      xxxxxxx, G(SE_3), G(SE_1), G(SE_5), G(SE_7),
      xxxxxxx, xxxxxxx, xxxxxxx, G(SE_8), xxxxxxx,      xxxxxxx, G(SE_9), G(SE_H), G(SE_L), xxxxxxx,
                                 _______, G(KC_SPC),    _______, _______
    ),
    [_FUN] = LAYOUT(
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,       KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
      xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   xxxxxxx,      xxxxxxx, KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx,
                                 _______, _______,      _______, _______
    ),
    [_SPEC] = LAYOUT(
      SE_TILD, _______, _______, _______, _______,      _______, _______, _______, SE_CIRC, SE_DIAE,
      _______, _______, _______, _______, SE_ACUT,      SE_GRV,  SYM_LFT, SYM_DWN, SYM_UP,  SYM_RHT,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                 FUN,     _______,      _______, _______
    )
};

// Keyboard utils

static uint16_t last_key_up = KC_NO;

static bool linux_mode = true;
bool in_linux(void) {
    return linux_mode;
}

static bool swap_caps_escape = false;
bool is_caps_swapped(void) {
    return swap_caps_escape;
}

bool tap_undead_key(bool key_down, uint16_t code) {
    if (key_down) {
        tap_code16(code);
        tap_code16(KC_SPACE);
    }
    return false;
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

void swap_caps_esc(void) {
    swap_caps_escape = !swap_caps_escape;
#   ifdef OLED_DRIVER_ENABLE
        oled_on();
#   endif
}

void tg_nix(void) {
    linux_mode = !linux_mode;
#   ifdef OLED_DRIVER_ENABLE
        oled_on();
#   endif
}

bool process_caps(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
    }
    return true;
}

bool process_escape(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_CAPS);
        } else {
            unregister_code(KC_CAPS);
        }
        return false;
    }
    return true;
}

void tap_escape(void) {
    tap_code(swap_caps_escape ? KC_CAPS : KC_ESC);
}

void tap_caps_lock(void) {
    tap_code(swap_caps_escape ? KC_ESC : KC_CAPS);
}

void enable_gaming(void) {
    /* autoshift_disable(); */
    /* layer_on(_GAME); */
}
void disable_gaming(void) {
    /* autoshift_enable(); */
    /* layer_off(_GAME); */
    /* layer_off(_GAME2); */
}

void tap_space_shift(uint16_t key, bool key_down) {
    if (key_down) {
        tap_code16(key);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code16(KC_SPC);
    double_tap(keycode);
    tap_code16(KC_SPC);
}

uint16_t corresponding_swe_key(uint16_t keycode) {
    switch (keycode) {
        case SE_LPRN:
            return SE_ARNG;
        case SE_ARNG:
            return SE_LPRN;
        case SE_RPRN:
            return SE_ADIA;
        case SE_ADIA:
            return SE_RPRN;
        case SE_UNDS:
            return SE_ODIA;
        case SE_ODIA:
            return SE_UNDS;
        default:
            return KC_NO;
    }
}

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        case tab_sym:
        case escape_ctrl:
        case scln_mod:
        case coln_ctrl:
        case enter_sym:
        case dquo:
        case quot:
        case dlr:
        case vsp:
            return COMBO_TERM;
        // Vertical combos, very relaxed
        case small_left_arrow:
        case lt_eq:
        case large_right_arrow:
        case small_right_arrow:
        case pipe_to:
        case sp:
        case sc_comb:
        case gt_eq:
            return COMBO_TERM + 55;
        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 25;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case del:
        case backsp:
        case wbacksp:
        case q_comb:
        case qu_comb:
        case sc_comb:
        case z_comb:
        case num:
        case comb_perc:
        case comb_grv:
        case comb_hash:
        case comb_pipe:
        case comb_ques:
        case comb_exlm:
        case comb_ampr:
        case comb_labk:
        case comb_rabk:
        case comb_lcbr:
        case comb_at:
        case rev_rep:
        case lprn_arng:
        case rprn_adia:
        case unds_odia:
        case eql:
        case gui_combo_l:
        case gui_combo_r:
        case ctrl_combo_l:
        case ctrl_combo_r:
        case ctrl_s_combo_l:
        case ctrl_s_combo_r:
        case shift_combo_l:
        case shift_combo_r:
        case close_win:
        case tab_sym:
        case enter_sym:
        case scln_mod:
        case escape_ctrl:
        case coln_ctrl:
            return false;
        default:
            return true;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo) {
    // FIXME this doesn't seem to work?
    return true;
}

// Tapping terms

#ifdef TAPPING_TERM_PER_KEY

#define THUMB_TERM 20
#define INDEX_TERM -20
#define MIDDLE_TERM 0
#define RING_TERM 80
#define PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_SPC:
            return TAPPING_TERM + THUMB_TERM;
        case DN_CTRL:
            return TAPPING_TERM + MIDDLE_TERM;
        default:
            return TAPPING_TERM;
    }
}
#endif

// Case modes

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case REPEAT:
        case REV_REP:
            return false;
        case SE_A ... KC_Z:
        case SE_1 ... KC_0:
        case QU:
        case SC:
        case SE_MINS:
        case SE_UNDS:
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

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_CTRL_SHFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
        case SCLN_MOD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_pre(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot_pre(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot_pre(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_post(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot_post(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot_post(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_post(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
}

void process_ctrl_shift(keyrecord_t *record) {
    process_oneshot_key(OS_SHFT, record);
    process_oneshot_key(OS_CTRL, record);
}

// Tap hold

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case SE_DQUO:
        case SE_LABK:
        case SE_RABK:
        case SE_DOT:
        case SE_PERC:
        case GRV:
        case SE_AT:
        case SE_PIPE:
        case SE_EXLM:
        case SE_AMPR:
        case SE_QUES:
        case SE_HASH:
        case SE_LPRN:
        case SE_LCBR:
        case SE_LBRC:
        case SE_EQL:
        case SE_UNDS:
        case SE_0:
        case G(SE_0):
        case G(SE_1):
        case G(SE_2):
        case G(SE_3):
        case G(SE_4):
        case G(SE_5):
        case G(SE_6):
        case G(SE_7):
        case G(SE_8):
        case G(SE_9):
        case G(SE_K):
        case G(SE_J):
        case G(SE_W):
        case G(SE_E):
        case G(SE_R):
        case G(SE_C):
        case SE_A ... SE_Z:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
        case LPRN_ARNG:
        case RPRN_ADIA:
        case UNDS_ODIA:
        case QU:
        case SC:
        case CLOSE_WIN:
        case C(SE_A):
        case C(SE_C):
        case C(SE_W):
        case C(SE_F):
        case C(SE_E):
        case C(SE_R):
        case C(SE_S):
        case C(SE_T):
        case C(SE_H):
        case C(SE_X):
        case C(SE_V):
        case C(SE_G):
        case C(SE_D):
        case C(SE_B):
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case GRV:
            register_key_to_repeat(keycode);
            tap_undead_key(true, SE_GRV);
            return;
        case LPRN_ARNG:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_LPRN);
            } else {
                tap16_repeatable(SE_ARNG);
            }
            return;
        case RPRN_ADIA:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_RPRN);
            } else {
                tap16_repeatable(SE_ADIA);
            }
            return;
        case UNDS_ODIA:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_UNDS);
            } else {
                tap16_repeatable(SE_ODIA);
            }
            return;
        case QU:
            send_string("qu");
            return;
        case SC:
            send_string("sc");
            return;
        case SE_Q:
        case SE_Z:
            if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
                tap16_repeatable(C(keycode));
            } else {
                tap16_repeatable(keycode);
            }
            return;
        case CLOSE_WIN:
            tap_escape();
            tap_code16(SE_COLN);
            tap_code(SE_Q);
            tap_code(KC_ENT);
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case SE_LABK:
        case SE_RABK:
        case SE_UNDS:
            // FIXME should be repeatable
            double_tap(keycode);
            return;
        case SE_DQUO:
        case SE_DOT:
        case SE_0:
            triple_tap(keycode);
            return;
        case SE_PERC:
            send_string("%{}");
            return;
        case GRV:
            tap_undead_key(true, SE_GRV);
            tap_undead_key(true, SE_GRV);
            tap_undead_key(true, SE_GRV);
            return;
        case SE_AT:
            tap_code16(SE_AT);
            tap16_repeatable(SE_U);
            return;
        case SE_PIPE:
        case SE_AMPR:
        case SE_EQL:
            double_tap_space(keycode);
            return;
        case SE_EXLM:
            send_string(" != ");
            return;
        case SE_QUES:
            send_string("{:?}");
            return;
        case SE_HASH:
            send_string("{:#?}");
            return;
        case SE_LPRN:
            double_parens_left(keycode, SE_RPRN);
            return;
        case SE_LCBR:
            double_parens_left(keycode, SE_RCBR);
            return;
        case SE_LBRC:
            double_parens_left(keycode, SE_RBRC);
            return;
        case LPRN_ARNG:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_LPRN);
            } else {
                tap16_repeatable(S(SE_ARNG));
            }
            return;
        case RPRN_ADIA:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_RPRN);
            } else {
                tap16_repeatable(S(SE_ADIA));
            }
            return;
        case UNDS_ODIA:
            if (IS_LAYER_ON(_SWE)) {
                tap16_repeatable(SE_UNDS);
            } else {
                tap16_repeatable(S(SE_ODIA));
            }
            return;
        case QU:
            send_string("Qu");
            return;
        case SC:
            send_string("Sc");
            return;
        case CLOSE_WIN:
            tap16_repeatable(S(G(SE_C)));
            return;
        case SE_Q:
        case SE_Z:
            if (IS_LAYER_ON(_SHRT) || get_oneshot_layer() == _SHRT) {
                tap16_repeatable(S(C(keycode)));
            } else {
                tap16_repeatable(S(keycode));
            }
            return;
        default:
            tap16_repeatable(S(keycode));
    }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // Extra
        case CLOSE_WIN:
            return 160;
        // Thumb
        case SE_E:
            return 120;
        // Pinky
        case SE_R:
        case SE_COMM:
        case SE_UNDS:
        case UNDS_ODIA:
        case SE_6:
        case G(SE_6):
        case SE_7:
        case G(SE_7):
        case C(SE_R):
        case C(SE_X):
            return 135;
        // Ring
        case SE_J:
        case SE_C:
        case SE_S:
        case SE_V:
        case SE_U:
        case SE_DOT:
        case SE_I:
        case SE_RPRN:
        case RPRN_ADIA:
        case SE_Q:
        case QU:
        case SE_4:
        case G(SE_4):
        case SE_5:
        case G(SE_5):
        case G(SE_J):
        case G(SE_R):
        case C(SE_A):
        case C(SE_C):
        case C(SE_S):
        case C(SE_V):
            return 105;
        // Middle
        case SE_Y:
        case SE_T:
        case SE_G:
        case SE_O:
        case SE_A:
        case SE_LPRN:
        case LPRN_ARNG:
        case SE_Z:
        case SE_0:
        case G(SE_0):
        case SE_1:
        case G(SE_1):
        case C(SE_W):
        case C(SE_T):
        case C(SE_G):
            return 100;
        // Slow index
        case SE_P:
        case SE_X:
        case C(SE_E):
            return 105;
        // Index
        default:
            return 100;
    }
}

// https://github.com/andrewjrae/kyria-keymap#userspace-leader-sequences
void *leader_toggles_func(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            layer_invert(_NUM);
            return NULL;
        case KC_S:
            layer_invert(_SYM);
            return NULL;
        case KC_C:
            swap_caps_esc();
            return NULL;
        default:
            return NULL;
    }
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T:
            return leader_toggles_func;
        case KC_C:
            tap_caps_lock();
            return NULL;
        default:
            return NULL;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        last_key_up = keycode;
    }

    if (!process_leader(keycode, record)) {
        return false;
    }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_roll(keycode, record)) {
        return false;
    }
    if (!process_tap_hold(keycode, record)) {
        // Extra register here to allow fast rolls without waiting for tap hold,
        // (which will also overwrite this).
        if (record->event.pressed) {
            register_key_to_repeat(keycode);
        }
        return false;
    }

    switch (keycode) {
        case ESC_CTRL:
            if (record->tap.count && record->event.pressed) {
                tap_escape();
                return false;
            }
            break;
        case KC_CAPS:
            return process_caps(record->event.pressed);
        case TG_NIX:
            if (record->event.pressed) {
                tg_nix();
            }
            return false;
        case TG_CAPS:
            if (record->event.pressed) {
                swap_caps_esc();
            }
            return false;
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(_BASE);
            return false;
        case CANCEL:
            layer_off(_NUM);
            layer_off(_SYM);
            stop_leading();
            //disable_gaming();
            return false;
        case TILD:
            register_key_to_repeat(TILD);
            return tap_undead_key(record->event.pressed, SE_TILD);
        case CIRC:
            register_key_to_repeat(CIRC);
            return tap_undead_key(record->event.pressed, SE_CIRC);
        case TO_NUM:
            layer_on(_NUM);
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_escape();
                tap_code16(SE_COLN);
                tap_code(SE_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(SE_W));
                tap_code(SE_S);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(SE_W));
                tap_code(SE_V);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(SE_G));
            }
            return false;
        // Workaround for taps only supporting standard keycodes
        case SCLN_MOD:
            if (record->tap.count && record->event.pressed) {
                tap16_repeatable(SE_SCLN);
                return false;
            }
            break;
        case COLN_CTRL:
            if (record->tap.count && record->event.pressed) {
                tap16_repeatable(SE_COLN);
                return false;
            }
            break;
        case ENT_SYM:
            if (record->tap.count && record->event.pressed) {
                // Manually disable for enter.
                // If we try to rely on `process_num_word` to disable NUMWORD,
                // then it will be disabled before we reach this point preventing
                // us from overriding.
                if (IS_LAYER_ON(_NUM)) {
                    tap16_repeatable(KC_PENT);
                } else {
                    tap16_repeatable(KC_ENT);
                }
                disable_num_word();
                return false;
            }
            break;
        /* case TO_GAME: */
        /*     if (record->event.pressed) { */
        /*         enable_gaming(); */
        /*     } */
        /*     return false; */
        case OS_CTRL_SHFT:
            process_ctrl_shift(record);
            return false;
        case TG_SWE:
            if (record->event.pressed) {
                uint16_t swe_key = corresponding_swe_key(last_key());
                if (swe_key != KC_NO) {
                    tap_code16(KC_BSPACE);
                    tap_code16(swe_key);
                }
                layer_invert(_SWE);
            }
            return false;
        case LEADER:
            start_leading();
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    bool res = _process_record_user(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register it here by default.
    // Ignore Space to not interfere with NAV toggling.
    if (res && record->event.pressed && keycode != MT_SPC) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    return res;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

