#pragma once

#include <stdint.h>
#include QMK_KEYBOARD_H

// Rolls can be overridden if they're faster than this.
#define ROLL_OVERRIDE_TERM 280

// Process roll, place in process_record_user().
// If this returns false, we should also return false from process_record_user().
bool process_roll(uint16_t keycode, const keyrecord_t *record);

// User can override this to override the currrent key to something else.
uint16_t roll_override(uint16_t lastkey, uint16_t keycode);
