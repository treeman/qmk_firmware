#pragma once

#include QMK_KEYBOARD_H

#include "keymap_swedish.h"
#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"

enum layers {
    _BASE = 0,
    _SECOND,
    // _SWE,
    _NUM,
    // _SYM,
    // _MODS,
    // _FUN,
    // _SPEC,
    // _WIN,
    // _NAV,
    // _WNAV,
    // _ARROW,
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = QK_USER,
    GRV,
    CIRC,

    // Vim
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
    CLOSE_WIN,

    // Multiple chars
    QU,
    SC,
    AT_U,

    // É
    E_ACUT,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Custom Win + Alt for window toggling on Windows
    WIN_ALT,

    // Shift on hold, Ctrl + A on tap
    // SFT_CA,

    // Mix Ctrl + key on hold, regular key on tap
    PGUP_CA,
    PGDN_CC,
    BTN3_CV,
    HOME_CX,
    DOWN_CC,

    // TODO why use these?
    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Toggle DPI setting up/down
    UP_DPI,
    DN_DPI,

    // Layer management
    CLEAR,

    TG_SWE,

    // Instant leader key
    LEADER,

    // Repeat keys
    REPEAT,
    REV_REP,

    // XCASE things
    // XCASE_MINS,
    // XCASE_SHFT,
    // XCASE_UNDS,

    // - and _ swappable keys
    UND_MIN,
    MIN_UND,
    SWAP_UND_MIN,
};

#define xxxxxxx KC_NO

#define PGUP_S MT(MOD_LSFT, KC_PGUP)

#define MT_SPC LT(_SECOND, KC_SPC)
#define MY_RALT OSM(MOD_RALT)
#define DN_CTRL LCTL_T(KC_DOWN)

#define ESC_SYM LT(_SYM, KC_ESC)
#define TAB_MOD LT(_MODS, KC_TAB)

#define COMM_AR LT(_ARROW, SE_COMM)
#define COLN_SYM LT(_SYM, SE_COLN)

// #define C_TAB C(KC_TAB)
#define C_C_TAB LCTL_T(C(KC_TAB))
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))
// #define SFT_CA LSFT_T(C(SE_A))

#define MY_LALT OSM(MOD_LALT)

#define SHRT OSL(_SHRT)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
#define OPT OSL(_OPT)
#define SPEC OSL(_SPEC)
#define FUN OSL(_FUN)

#define SYM_TM UC(0x2122)
#define SYM_EUR ALGR(SE_E)
#define SYM_COP C(ALGR(SE_C))
