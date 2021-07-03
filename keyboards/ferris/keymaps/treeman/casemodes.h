#pragma once

#include QMK_KEYBOARD_H

// Check whether caps word is on
bool caps_word_enabled(void);
// Enable caps word
void enable_caps_word(void);
// Disable caps word
void disable_caps_word(void);
// Toggle caps word
void toggle_caps_word(void);

// Check whether xcase is on
bool xcase_enabled(void);
// Check whether xcase is waiting for a keypress
bool xcase_waiting(void);
// Enable xcase and pickup the next keystroke as the delimiter
void enable_xcase(void);
// Enable xcase with the specified delimiter
void enable_xcase_with(uint16_t delimiter);
// Disable xcase
void disable_xcase(void);

// Function to be put in process user
bool process_case_modes(uint16_t keycode, const keyrecord_t *record);
