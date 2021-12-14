#include "roll.h"
#include <stdint.h>
#include "timer.h"

#include "keycodes.h"

static uint16_t overridden_key = KC_NO;
static uint16_t resulting_key = KC_NO;
static uint16_t timer = 0;
static uint16_t lastkey = KC_NO;

void end_roll(void) {
    overridden_key = KC_NO;
    resulting_key = KC_NO;
}

bool process_roll(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        uint16_t override = roll_override(lastkey, keycode);
        if (overridden_key == KC_NO // Can only start a new override when the last one has finished.
                && override != KC_NO && override != keycode 
                && timer_elapsed(timer) < ROLL_OVERRIDE_TERM) {
            // Found a key we should override as a matching pair was detected within the time treshold.
            overridden_key = keycode;
            resulting_key = override;
        } else {
            // Restart our roll check.
            end_roll();
            timer = timer_read();
            lastkey = keycode;
        }
    }

    if (overridden_key == keycode) {
        // Override the key
        if (record->event.pressed) {
            register_code16(resulting_key);
        } else {
            unregister_code16(resulting_key);
            // Now we can start a new override.
            end_roll();
        }
        return false;
    }

    return true;
}

__attribute__ ((weak))
uint16_t roll_override(uint16_t lastkey, uint16_t keycode) {
    // Add overrides like this:
    /* if (lastkey == REPEAT && keycode == SE_U) { */
    /*     return SE_A; */
    /* } */
    /* if (lastkey == SE_U && keycode == REPEAT) { */
    /*     return SE_I; */
    /* } */

    return KC_NO;
}
