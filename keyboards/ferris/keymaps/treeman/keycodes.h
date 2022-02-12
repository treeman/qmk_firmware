#pragma once

#include QMK_KEYBOARD_H

#include "keymap_swedish.h"
#include "quantum.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _SWE,
    _NUM,
    _NAV,
    _WNAV,
    _SYM,
    _MODS,
    _SHRT,
    _SPEC,
    _FUN,
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = SAFE_RANGE,
    GRV,
    CIRC,

    // Misc
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
    CLOSE_WIN,

    // Multiple chars
    QU,
    SC,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // ÅÄÖ or ()_ combos
    // LPRN_ARNG,
    // RPRN_ADIA,
    // UNDS_ODIA,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    OS_CTRL_SHFT,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Layer management
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR, // Clear all WORD, one-shots and reset to BASE

    TO_NUM,
    TG_SWE,

    // Instant leader key
    LEADER,

    // Repeat keys
    REPEAT,
    REV_REP,

    // Smileys
    // SHRUGIE,        // ┐(°‿°)┌ (nicer) or 乁(ツ)ㄏ (whatever)
    // TABLE_F,        // (╯°□°)╯ ︵ ┻━┻ or (ノಠ益ಠ)ノ彡┻━┻
    // FACE_1,         // ✖‿✖ (excited) or (╯︵╰,) (crying)
    // FACE_2,         // (¬‿¬) (skeptical) or ಠ_ಠ (disapproval)

    // Runtime options
    TG_NIX,
    TG_CAPS,
};

#define xxxxxxx KC_NO

// #define HOME_LINDEX(kc)         (LSFT_T(kc))
// #define HOME_RINDEX(kc)         (LSFT_T(kc))
//
// #define HOME_LMIDDLE(kc)        (LCTL_T(kc))
// #define HOME_RMIDDLE(kc)        (RCTL_T(kc))
//
// #define HOME_LRING(kc)          (LGUI_T(kc))
// #define HOME_RRING(kc)          (RGUI_T(kc))
//
// #define HOME_LPINKY(kc)         (LALT_T(kc))
// #define HOME_RPINKY(kc)         (LALT_T(kc))

// #define MT_BTN1 LGUI_T(KC_BTN1)
#define MT_SPC LT(_NAV, KC_SPC)
// #define SFT OSM(MOD_LSFT)
// #define ALT OSM(MOD_LALT)
#define MY_RALT OSM(MOD_RALT)
// #define CTRL OSM(MOD_LCTL)
// #define GUI OSM(MOD_LGUI)
#define DN_CTRL LCTL_T(KC_DOWN)

#define ESC_SYM LT(_SYM, KC_ESC)
#define TAB_MOD LT(_MODS, KC_TAB)

#define COLN_SYM LT(_SYM, SE_COLN)

#define C_TAB C(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define SHRT OSL(_SHRT)
// #define NUM MO(_NUM)
// #define TG_NUM TG(_NUM)
// #define G_WNAV LM(_WNAV, MOD_LGUI)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
// #define TG_SWE
// #define TG_SWE TG(_SWE)
#define OPT OSL(_OPT)
#define SPEC OSL(_SPEC)
#define FUN OSL(_FUN)

#define GAME2 OSL(_GAME2)

#define SYM_LFT ALGR(SE_Y) // ← y
#define SYM_DWN ALGR(SE_U) // ↓ u
#define SYM_RHT ALGR(SE_I) // → i
#define SYM_UP ALGR(S(SE_U)) // ↑ U
#define SYM_LDQ ALGR(SE_V) // “ v
#define SYM_RDQ ALGR(SE_B) // ” b
#define SYM_LQO ALGR(S(SE_V)) // ‘ V
#define SYM_RQO ALGR(S(SE_B)) // ’ B
