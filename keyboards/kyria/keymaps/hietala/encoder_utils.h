#pragma once

#include <stdbool.h>

#include "keycodes.h"

typedef enum {
    LENC_MODE_PAGING = 0,
    LENC_MODE_SHIFT_TAB,
    LENC_MODE_CTRL_TAB,
    _LENC_MODE_LAST  // Do not use, except for looping through enum values
} left_encoder_mode_t;

typedef enum {
    RENC_MODE_VOLUME = 0,
    _RENC_MODE_LAST  // Do not use, except for looping through enum values
} right_encoder_mode_t;

left_encoder_mode_t encoder_left_mode;
right_encoder_mode_t encoder_right_mode;

void cycle_left_encoder_mode(bool reverse);
void cycle_right_encoder_mode(bool reverse);

void action_left_encoder(bool clockwise);
void action_right_encoder(bool clockwise);

