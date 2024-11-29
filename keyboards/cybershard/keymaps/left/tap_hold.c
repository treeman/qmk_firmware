#include "tap_hold.h"

static bool     in_progress  = false;
static uint16_t timer        = 0;
static uint16_t lastkey      = KC_NO;
static uint16_t hold_timeout = 0;

bool process_tap_hold(uint16_t keycode, const keyrecord_t *record) {
    // Only process tap hold for specified keys
    if (!tap_hold(keycode)) return true;

    if (record->event.pressed) {
        end_tap_hold();
        in_progress  = true;
        timer        = timer_read();
        lastkey      = keycode;
        hold_timeout = tap_hold_timeout(keycode);
    } else {
        if (in_progress && keycode == lastkey && timer_elapsed(timer) < hold_timeout) {
            end_tap_hold();
        }
    }

    return false;
}

void tap_hold_matrix_scan() {
    if (in_progress && timer_elapsed(timer) >= hold_timeout) {
        in_progress = false;
        tap_hold_send_hold(lastkey);
    }
}

void end_tap_hold() {
    if (in_progress) {
        in_progress = false;
        tap_hold_send_tap(lastkey);
    }
}

__attribute__((weak)) void tap_hold_send_tap(uint16_t keycode) {
    tap_code16(keycode);
}

__attribute__((weak)) void tap_hold_send_hold(uint16_t keycode) {
    tap_code16(S(keycode));
}

__attribute__((weak)) uint16_t tap_hold_timeout(uint16_t keycode) {
    return 135;
}

__attribute__((weak)) bool tap_hold(uint16_t keycode) {
    return false;
}
