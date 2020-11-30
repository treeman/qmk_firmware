#pragma once
#include "keymap_finnish.h"

enum customKeycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    CODEBLK, // `code`
    TB_B_UP, // Trackball brightness
    TB_B_DN,
    ALTSHFT, // alternate shifted and non shifted
    // from combos:
    MY_VIM_V,
    MY_VIM_S,
    MY_VIM_C,
    MY_VIM_CW,
    MY_PARENSBOTH,
    MY_SQUAREBRACEBOTH,
    MY_CURLYBRACEBOTH,
};

enum my_layers {
    _BASE = 0, // default layer
    _SYMB, // numbers and symbols
    _MOUS,
    _GAME, // gaming layer
    _FUNC, // function layer
    _STUF, // reset and maybe some other stuff
};

__attribute__((unused))
extern uint8_t tb_brightness;

// left thumb keys (no ignore_mod_tap_interrupt)
#define  MY_THL1  LCTL_T(KC_BSPC)
#define  MY_THL2  LALT_T(KC_SPC)
#define  MY_THL3  KC_LGUI
#define  MY_THL4  KC_MS_BTN1

// right thumb keys
#define  MY_THR1  LT(_FUNC, KC_ENT)
#define  MY_THR2  RSFT_T(KC_SPC)
#define  MY_THR3  MO(_SYMB)
#define  MY_THR4  RALT_T(KC_INS)

// basic alpha keys {{{
#define  MY_Q  KC_Q
#define  MY_W  KC_W
#define  MY_E  KC_E
#define  MY_R  KC_R
#define  MY_T  KC_T
#define  MY_Y  KC_Y
#define  MY_U  KC_U
#define  MY_I  KC_I
#define  MY_O  KC_O
#define  MY_P  KC_P

#define MY_A  KC_A
#define MY_S  KC_S
#define MY_D  KC_D
#define MY_F  KC_F
#define MY_G  KC_G
#define MY_H  KC_H
#define MY_J  KC_J
#define MY_K  KC_K
#define MY_L  KC_L
#define MY_OE FI_ODIA
#define MY_AE LCTL_T(FI_ADIA)

#define  MY_Z     KC_Z
#define  MY_X     KC_X
#define  MY_C     KC_C
#define  MY_V     KC_V
#define  MY_B     KC_B
#define  MY_N     KC_N
#define  MY_M     KC_M
#define  MY_COMM  KC_COMM
#define  MY_DOT   KC_DOT
/* #define  MY_DOT   TD(TD_SEEND_DOT) */
#define  MY_MINS  FI_MINS
//}}}

// other keys
#define CTRLTAB LCTL(KC_TAB)
#define CSFTTAB LCTL(LSFT(KC_TAB))
#define CTRLESC CTL_T(KC_ESC)

#ifdef TAP_DANCE_ENABLE
// tap dances {{{
enum tapdance_buttons {
    TD_HOME_END = 0,
    TD_PSCR_INS,
    TD_HOME_END_MOD,
    TD_SEEND_DOT,
    TD_SEEND_QUES,
    TD_SEEND_EXLM,
};
#define HOMEND TD(TD_HOME_END)
#define PSCRINS TD(TD_PSCR_INS)
#define TD_HEMD TD(TD_HOME_END_MOD)
// }}}
#endif

#include "action_tapping.h"
void trigger_tapping(void);

// SEND_STRING shortcuts
#define SLEFT SS_TAP(X_LEFT)
