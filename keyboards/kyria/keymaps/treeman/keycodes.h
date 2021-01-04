#pragma once

#include "keymap_swedish.h"
#include "quantum.h"

enum layers {
    _BASE = 0,
    _NUM,
    _FUN,
    _MISC,
    _MOVE
};

enum custom_keycodes {
    L_ENCM = SAFE_RANGE,
    R_ENCM
};

#define xxxxxxx KC_NO


/*
 * Reinsert these when we've learned the layout better
#define MY_R LGUI_T(SE_R)
#define MY_S LALT_T(SE_S)
#define MY_T LCTL_T(SE_T)
#define MY_H LSFT_T(SE_H)

#define MY_N RSFT_T(SE_N)
#define MY_A RCTL_T(SE_A)
#define MY_I LALT_T(SE_I)
#define MY_O RGUI_T(SE_O)
*/

#define MY_R SE_R
#define MY_S SE_S
#define MY_T SE_T
#define MY_H SE_H

#define MY_N SE_N
#define MY_A SE_A
#define MY_I SE_I
#define MY_O SE_O

#define MY_SPC KC_SPACE
#define MY_E SE_E


#define MY_ESC KC_ESC
#define MY_ENT KC_ENTER

#define MY_LSFT OSM(MOD_LSFT)
#define MY_RSFT OSM(MOD_RSFT)
#define MY_LCTL OSM(MOD_LCTL)
#define MY_RCTL OSM(MOD_RCTL)

#define MY_NUM OSL(_NUM)
#define MY_FUN OSL(_FUN)


