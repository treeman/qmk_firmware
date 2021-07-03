#pragma once

#include QMK_KEYBOARD_H

// Register a keycode we should repeat with the repeat key
void register_key_to_repeat(uint16_t keycode);
// Repeat key actions
void update_repeat_key(keyrecord_t *record);
void update_reverse_repeat_key(keyrecord_t *record);
