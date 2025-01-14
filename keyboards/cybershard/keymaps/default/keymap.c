// Copyright 2024 Jonas Hietala
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "sendstring_swedish.h"
#include "g/keymap_combo.h"
#include "print.h"
#include "timer.h"

#include "keycodes.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "leader.h"

// Maybe use built-in QMK implementations:
// - Repeat
// - Reverse repeat
// - One shot mods
// - CAPSWORD

// [_MOUSE]  = LAYOUT(
//   xxxxxxx, C(SE_C), xxxxxxx, xxxxxxx, xxxxxxx,      _______, _______, _______, _______, _______,
//   SFT_CA,  KC_BTN2, KC_BTN3, KC_BTN1, xxxxxxx,      _______, _______, _______, _______, _______,
//   C(SE_X), KC_BTN4, KC_BTN5, xxxxxxx, xxxxxxx,      _______, _______, _______, _______, _______,
//            DN_DPI,  UP_DPI,
//                              _______, MT_SPC,       _______
// ),
// [_NAV]  = LAYOUT(
//   G(SE_J), PGDN_CC, KC_UP,   KC_PGUP, HOME_CX,      xxxxxxx, G(SE_W), G(SE_E), G(SE_R), xxxxxxx,
//   C(SE_A), SC_TAB,  DN_CTRL, C_TAB,   G(SE_K),      xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
//   KC_LSFT, BTN3_CV, KC_BTN2, KC_BTN1, KC_END,       xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
//            KC_BTN4, KC_BTN5,
//                              _______, MT_SPC,       WNAV
// ),

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      SE_J,    SE_C,    SE_Y,    SE_F,    SE_P,         SE_X,    SE_W,    SE_O,    SE_U,    SE_DOT,
      SE_R,    SE_S,    SE_T,    SE_H,    SE_K,         SE_M,    SE_N,    SE_A,    SE_I,    REPEAT,
      COMM_AR, SE_V,    SE_G,    SE_D,    SE_B,         SE_SLSH, SE_L,    SE_LPRN, SE_RPRN, UND_MIN_MOUSE,
               KC_F2,   KC_F12,
                                 FUN,     MT_SPC,       SE_E
    ),
    [_SWE]  = LAYOUT(
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, SE_ARNG, SE_ADIA, SE_ODIA,
               _______, _______,
                                _______, _______,      _______
    ),
    [_NAV]  = LAYOUT(
      G(SE_J), C(SE_C), xxxxxxx, C(SE_F), END_CX,       KC_HOME, G(SE_W), G(SE_E), G(SE_R), G(SE_DOT),
      SFT_CA,  SC_TAB,  C_C_TAB, KC_BTN1, G(SE_K),      xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    G(SE_COMM),C(SE_V), KC_BTN2, KC_PGDN, C(SE_D),      C(SE_U), KC_PGUP, xxxxxxx, xxxxxxx, xxxxxxx,
               KC_BTN4, KC_BTN5,
                                 _______, MT_SPC,       WNAV
    ),
    [_ARROW]  = LAYOUT(
      _______, KC_PGUP, KC_UP,   KC_PGDN, KC_END,       KC_HOME, _______, _______, _______, _______,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
      COMM_AR, _______, _______, KC_PGDN, _______,      _______, KC_PGUP, _______, _______, _______,
               _______, _______,
                                _______, _______,      _______
    ),
    [_MOUSE]  = LAYOUT(
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      KC_BTN3, KC_BTN1, KC_BTN2, _______, UND_MIN_MOUSE,
               _______, _______,
                                _______, _______,      _______
    ),
    [_WIN]  = LAYOUT(
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      _______, S_TAB,   _______, KC_TAB,  _______,      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
               _______, _______,
                                 _______, _______,      _______
    ),
    [_NUM]  = LAYOUT(
      SE_J,    SE_PLUS, SE_ASTR, SE_F,    SE_P,         SE_X,    SE_W,    AT_U,    REPEAT,  SE_DOT,
      SE_6,    SE_4,    SE_0,    SE_2,    SE_K,         SE_M,    SE_3,    SE_1,    SE_5,    SE_7,
      SE_COMM, SE_V,    NUM_G,   SE_8,    SE_B,         SE_SLSH, SE_9,    SE_LPRN, SE_RPRN, UND_MIN,
               _______, _______,
                                 _______, MT_SPC,       _______
    ),
    // Important that the symbols on the base layer have the same positions as these symbols
    [_SYM]  = LAYOUT(
      TILD,    SE_PLUS, SE_ASTR, xxxxxxx, xxxxxxx,      xxxxxxx, SE_HASH, SE_AT,   CIRC,    SE_DOT,
      SE_PIPE, SE_LCBR, SE_RCBR, MIN_UND, SE_BSLS,      GRV,     SE_QUES, SE_LBRC, SE_RBRC, REPEAT,
      SE_COMM, SE_LABK, SE_RABK, SE_EXLM, xxxxxxx,      SE_SLSH, SE_AMPR, SE_LPRN, SE_RPRN, UND_MIN,
               _______, _______,
                                 _______, _______,       _______
    ),
    [_MODS] = LAYOUT(
      _______, _______, _______, _______, _______,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      _______, _______, _______, _______, _______,      xxxxxxx, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,
      _______, _______, _______, _______, _______,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MY_RALT,
               _______, _______,
                                 _______, _______,      _______
    ),
    [_WNAV] = LAYOUT(
      G(SE_J), G(SE_C), xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, G(SE_W), G(SE_E), G(SE_R), xxxxxxx,
      G(SE_6), G(SE_4), G(SE_0), G(SE_2), G(SE_K),      xxxxxxx, G(SE_3), G(SE_1), G(SE_5), G(SE_7),
      xxxxxxx, xxxxxxx, xxxxxxx, G(SE_8), xxxxxxx,      xxxxxxx, G(SE_9), G(SE_H), G(SE_L), xxxxxxx,
               _______, _______,
                                 _______, G(KC_SPC),    WNAV
    ),
    [_FUN]  = LAYOUT(
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,       KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
      xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   xxxxxxx,      xxxxxxx, KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx,
               DN_DPI,  UP_DPI,
                                 FUN,     _______,      _______
    ),
    [_SPEC] = LAYOUT(
      SE_TILD, SYM_COP, _______, _______, _______,      _______, _______, _______, SE_CIRC, SE_DIAE,
      _______, _______, SYM_TM,  _______, SE_ACUT,      SE_GRV,  _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
               _______, _______,
                                 _______, _______,      SYM_EUR
    )
};
// clang-format on

// Keyboard utils

static bool scrolling_mode = false;
static bool speed_mode     = false;
static bool precision_mode = false;

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up   = KC_NO;

static bool swap_caps_escape = false;
static bool swap_unds_mins   = false;

// static uint16_t mouse_move_timer;

bool is_caps_swapped(void) {
    return swap_caps_escape;
}

bool tap_undead_key(bool key_down, uint16_t code) {
    if (key_down) {
        tap_code16(code);
        tap_code16(KC_SPACE);
    }
    return false;
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

void swap_caps_esc(void) {
    swap_caps_escape = !swap_caps_escape;
}

bool process_caps(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
    }
    return true;
}

void tap_escape(void) {
    tap_code(swap_caps_escape ? KC_CAPS : KC_ESC);
}

bool is_caps_lock_on(void) {
    return host_keyboard_led_state().caps_lock;
}

void tap_caps_lock(void) {
    tap_code(swap_caps_escape ? KC_ESC : KC_CAPS);
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code16(KC_SPC);
    double_tap(keycode);
    tap_code16(KC_SPC);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

uint16_t unds_mins_key(void) {
    return swap_unds_mins ? SE_MINS : SE_UNDS;
}

uint16_t mins_unds_key(void) {
    return swap_unds_mins ? SE_UNDS : SE_MINS;
}

uint16_t corresponding_swe_key(uint16_t keycode) {
    switch (keycode) {
        case SE_LPRN:
            return SE_ARNG;
        case SE_ARNG:
            return SE_LPRN;
        case SE_RPRN:
            return SE_ADIA;
        case SE_ADIA:
            return SE_RPRN;
        case UND_MIN:
        case UND_MIN_MOUSE:
            return SE_ODIA;
        case SE_ODIA:
            return unds_mins_key();
        default:
            return KC_NO;
    }
}

static uint16_t current_dpi = 1600;

void set_dpi(uint16_t dpi) {
    pointing_device_set_cpi(dpi);
}

void up_dpi(void) {
    if (current_dpi <= 15900) {
        current_dpi += 100;
    }
    dprintf("Set DPI: %u\n", current_dpi);
    set_dpi(current_dpi);
}

void down_dpi(void) {
    if (current_dpi >= 200) {
        current_dpi -= 100;
    }
    dprintf("Set DPI: %u\n", current_dpi);
    set_dpi(current_dpi);
}

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        case ctrl_combo_l:
        case escape_sym:
        case tab_mod:
        case del:
        case dquo:
        case coln_sym:
        case ctrl_combo_r:
        case quot:
        case ent:
        case vsp:
        case gui_combo_l:
        case gui_combo_r:
        case dlr:
            return COMBO_TERM;
        // Vertical combos, very relaxed
        case small_left_arrow:
        case lt_eq:
        case large_right_arrow:
        case small_right_arrow:
        case pipe_to:
        case sp:
        case gt_eq:
            return COMBO_TERM + 55;
        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 25;
    }
}

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    // Meh, it's not perfect but it's good enough.
    uprintf("COMBO,NA,NA,0,0,0,0,%u\n", combo_index);
    return false;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case del:
        case backsp:
        case q_comb:
        case qu_comb:
        case z_comb:
        case num:
        // case comb_perc:
        case perc:
        case comb_grv:
        case comb_hash:
        case comb_pipe:
        case comb_ques:
        case comb_exlm:
        case comb_ampr:
        case comb_labk:
        case comb_rabk:
        case comb_lcbr:
        case comb_lbrc:
        case comb_at:
        case comb_0:
        case comb_e_acut:
        // case rev_rep:
        case arng:
        case adia:
        case odia:
        case eql:
        case gui_combo_l:
        case gui_combo_r:
        case ctrl_combo_l:
        case ctrl_combo_r:
        case shift_combo_l:
        case shift_combo_r:
        case close_win:
        case escape_sym:
        case tab_mod:
        case coln_sym:
        case dquo:
        case lalt:
        // case mbutton:
        case comb_unds_mins:
        case win_alt:
            return false;
        default:
            return true;
    }
}

// Tapping terms

#define TAP_THUMB_TERM 20
#define TAP_INDEX_TERM -20
#define TAP_MIDDLE_TERM 0
#define TAP_RING_TERM 80
#define TAP_PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_SPC:
            return TAPPING_TERM + TAP_THUMB_TERM;
        case DN_CTRL:
            return TAPPING_TERM + TAP_MIDDLE_TERM;
        default:
            return TAPPING_TERM;
    }
}

// Case modes

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        case REPEAT:
        // Note that xcase strips mod taps and layer taps
        // case KC_SPC:
        // Only for xcase but broken for capsword.....
        // case MT_SPC:
        // printf("Check space\n");
        // if () {
        //     return record->event.pressed && last_key_up == MT_SPC;
        // } el
        case CAPSWORD:
        case NUMWORD:
        case REV_REP:
        case SE_A ... SE_Z:
        case SE_1 ... SE_0:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
        case QU:
        case SC:
        case SE_MINS:
        case SE_UNDS:
        case UND_MIN:
        case UND_MIN_MOUSE:
        case MIN_UND:
        case SWAP_UND_MIN:
        case SE_LPRN:
        case SE_RPRN:
        case KC_BSPC:
        case C(SE_W):
        case KC_DEL:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            } else {
                return false;
            }
        default:
            return record->event.pressed;
    }
}

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
        case TAB_MOD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

// Tap hold

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case SE_DQUO:
        case SE_LABK:
        case SE_RABK:
        case SE_DOT:
        case SE_PERC:
        case GRV:
        case SE_AT:
        case SE_PIPE:
        case SE_EXLM:
        case SE_AMPR:
        case SE_QUES:
        case SE_HASH:
        case SE_LPRN:
        case SE_LCBR:
        case SE_LBRC:
        case SE_EQL:
        case SE_UNDS:
        case UND_MIN:
        case MIN_UND:
        case SE_0:
        case G(SE_0):
        case G(SE_1):
        case G(SE_2):
        case G(SE_3):
        case G(SE_4):
        case G(SE_5):
        case G(SE_6):
        case G(SE_7):
        case G(SE_8):
        case G(SE_9):
        case G(SE_K):
        case G(SE_J):
        case G(SE_W):
        case G(SE_E):
        case G(SE_R):
        case G(SE_C):
        case SE_A ... SE_Z:
        case SE_ARNG:
        case SE_ADIA:
        case SE_ODIA:
        case QU:
        case SC:
        case E_ACUT:
        case CLOSE_WIN:
        case C(SE_A):
        case C(SE_C):
        case C(SE_W):
        case C(SE_F):
        case C(SE_E):
        case C(SE_R):
        case C(SE_S):
        case C(SE_T):
        case C(SE_H):
        case C(SE_X):
        case C(SE_V):
        case C(SE_G):
        case C(SE_D):
        case C(SE_B):
        case PGUP_CA:
        case PGDN_CC:
        case BTN3_CV:
        case HOME_CX:
        case END_CX:
        case DOWN_CC:
        case LR_MOUSE:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case GRV:
            register_key_to_repeat(keycode);
            tap_undead_key(true, SE_GRV);
            return;
        case QU:
            send_string("qu");
            return;
        case SC:
            send_string("sc");
            return;
        case SE_Q:
        case SE_Z:
            // if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
            //     tap16_repeatable(C(keycode));
            // } else {
            //     tap16_repeatable(keycode);
            // }
            tap16_repeatable(keycode);
            return;
        case E_ACUT:
            tap_code16(SE_ACUT);
            tap_code16(SE_E);
            return;
        case UND_MIN:
            tap16_repeatable(unds_mins_key());
            return;
        case MIN_UND:
            tap16_repeatable(mins_unds_key());
            return;
        case CLOSE_WIN:
            tap_code16(C(SE_W));
            tap_code(SE_Q);
            return;
        case PGUP_CA:
            tap16_repeatable(KC_PGUP);
            return;
        case PGDN_CC:
            tap16_repeatable(KC_PGDN);
            return;
        case DOWN_CC:
            tap16_repeatable(KC_DOWN);
            return;
        case BTN3_CV:
            tap16_repeatable(KC_BTN3);
            return;
        case HOME_CX:
            tap16_repeatable(KC_HOME);
            return;
        case END_CX:
            tap16_repeatable(KC_END);
            return;
        case LR_MOUSE:
            tap16_repeatable(KC_BTN1);
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case SE_LABK:
        case SE_RABK:
        case SE_UNDS:
            // FIXME should be repeatable
            double_tap(keycode);
            return;
        case UND_MIN:
            double_tap(unds_mins_key());
            return;
        case MIN_UND:
            double_tap(mins_unds_key());
            return;
        case SE_DQUO:
        case SE_DOT:
        case SE_0:
            triple_tap(keycode);
            return;
        case SE_PERC:
            send_string("%{}");
            return;
        case GRV:
            tap_undead_key(true, SE_GRV);
            tap_undead_key(true, SE_GRV);
            tap_undead_key(true, SE_GRV);
            return;
        case SE_AT:
            tap_code16(SE_AT);
            tap16_repeatable(SE_U);
            return;
        case SE_PIPE:
        case SE_AMPR:
        case SE_EQL:
            double_tap_space(keycode);
            return;
        case SE_EXLM:
            send_string(" != ");
            return;
        case SE_QUES:
            send_string("{:?}");
            return;
        case SE_HASH:
            send_string("{:#?}");
            return;
        case SE_LPRN:
            double_parens_left(keycode, SE_RPRN);
            return;
        case SE_LCBR:
            double_parens_left(keycode, SE_RCBR);
            return;
        case SE_LBRC:
            double_parens_left(keycode, SE_RBRC);
            return;
        case QU:
            send_string("Qu");
            return;
        case SC:
            send_string("Sc");
            return;
        case E_ACUT:
            tap_code16(SE_ACUT);
            tap_code16(S(SE_E));
            return;
        case CLOSE_WIN:
            tap16_repeatable(S(G(SE_C)));
            return;
        case SE_Q:
        case SE_Z:
            // if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
            //     tap16_repeatable(S(C(keycode)));
            // } else {
            //     tap16_repeatable(S(keycode));
            // }
            tap16_repeatable(S(keycode));
            return;
        case PGUP_CA:
            tap16_repeatable(C(SE_A));
            return;
        case PGDN_CC:
        case DOWN_CC:
            tap16_repeatable(C(SE_C));
            return;
        case BTN3_CV:
            tap16_repeatable(C(SE_V));
            return;
        case HOME_CX:
        case END_CX:
            tap16_repeatable(C(SE_X));
            return;
            tap16_repeatable(C(SE_X));
            return;
        case LR_MOUSE:
            tap16_repeatable(KC_BTN2);
            return;
        default:
            tap16_repeatable(S(keycode));
    }
}

#define TAP_HOLD_EXTRA 160
#define TAP_HOLD_THUMB 120
#define TAP_HOLD_PINKY 135
#define TAP_HOLD_RING 105
#define TAP_HOLD_MIDDLE 100
#define TAP_HOLD_INDEX 100
#define TAP_HOLD_INDEX_SLOW 105

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // Extra
        case CLOSE_WIN:
            return TAP_HOLD_EXTRA;
        // Thumb
        case SE_E:
            return TAP_HOLD_THUMB;
        // Pinky
        case SE_R:
        case SE_COMM:
        case SE_UNDS:
        case UND_MIN:
        case SE_6:
        case G(SE_6):
        case SE_7:
        case G(SE_7):
        case C(SE_R):
        case C(SE_X):
            return TAP_HOLD_PINKY;
        // Ring
        case SE_J:
        case SE_C:
        case SE_S:
        case SE_V:
        case SE_U:
        case SE_DOT:
        case SE_I:
        case SE_RPRN:
        case SE_Q:
        case QU:
        case SE_4:
        case G(SE_4):
        case SE_5:
        case G(SE_5):
        case G(SE_J):
        case G(SE_R):
        case C(SE_A):
        case C(SE_C):
        case C(SE_S):
        case C(SE_V):
            return TAP_HOLD_RING;
        // Middle
        case SE_Y:
        case SE_T:
        case SE_G:
        case SE_O:
        case SE_A:
        case SE_LPRN:
        case SE_Z:
        case SE_0:
        case G(SE_0):
        case SE_1:
        case G(SE_1):
        case C(SE_W):
        case C(SE_T):
        case C(SE_G):
            return TAP_HOLD_MIDDLE;
        // Slow index
        case SE_P:
        case SE_X:
        case C(SE_E):
            return TAP_HOLD_INDEX_SLOW;
        // Index
        default:
            return TAP_HOLD_INDEX;
    }
}

// https://github.com/andrewjrae/kyria-keymap#userspace-leader-sequences
void *leader_toggles_func(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            printf("Invert NUM\n");
            layer_invert(_NUM);
            return NULL;
        case KC_S:
            printf("Invert SYM\n");
            layer_invert(_SYM);
            return NULL;
        case KC_F:
            printf("Invert FUN\n");
            layer_invert(_FUN);
            return NULL;
        case KC_C:
            printf("Swap CAPS/ESC\n");
            swap_caps_esc();
            return NULL;
        default:
            return NULL;
    }
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T:
            return leader_toggles_func;
        case KC_C:
            printf("Tap CAPS LOCK\n");
            tap_caps_lock();
            return NULL;
        case KC_S:
            printf("Ctrl + Gui + Space\n");
            tap_code16(C(G(KC_SPACE)));
            return NULL;
        case ESC_SYM:
            printf("Ctrl + Shift + Escape\n");
            tap_code16(C(S(KC_ESC)));
            return NULL;
        default:
            return NULL;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    const bool is_combo = record->event.type == COMBO_EVENT;
    // clang-format off
    if (!is_combo) {
    uprintf("0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,%u\n",
        keycode,
        record->event.key.row,
        record->event.key.col,
        get_highest_layer(layer_state),
        record->event.pressed,
        get_mods(),
        get_oneshot_mods(),
        record->tap.count
    );
    }

    if (!process_leader(keycode, record)) {
        return false;
    }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_tap_hold(keycode, record)) {
        // Extra register here to allow fast rolls without waiting for tap hold,
        // (which will also overwrite this).
        if (record->event.pressed) {
            register_key_to_repeat(keycode);
        }
        return false;
    }

    switch (keycode) {
        case ESC_SYM:
            if (record->tap.count && record->event.pressed) {
                tap_escape();
                return false;
            }
            break;
        // case WNAV:
        //     if (record->event.pressed && IS_LAYER_ON(_MOUSE)) {
        //         printf("Disable mouse layer\n");
        //         layer_off(_MOUSE);
        //     }
        //     return true;
        // case MT_SPC:
        //     if (record->event.pressed) {
        //         if (!IS_LAYER_ON(_MOUSE) && timer_elapsed(mouse_move_timer) <= MOUSE_LAYER_ACTIVE_TIMEOUT) {
        //             printf("Enable mouse layer: %u\n", timer_elapsed(mouse_move_timer));
        //             layer_on(_MOUSE);
        //         }
        //     } else {
        //         if (IS_LAYER_ON(_MOUSE)) {
        //             printf("Disable mouse layer\n");
        //             layer_off(_MOUSE);
        //             // Reset the timer so we have to move the trackball again before the mouse layer can activate.
        //             mouse_move_timer = 0;
        //         }
        //     }
        //     return true;
        case KC_CAPS:
            return process_caps(record->event.pressed);
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            if (is_caps_lock_on()) {
                tap_caps_lock();
            }
            swap_unds_mins = false;
            stop_leading();
            layer_off(_NUM);
            layer_off(_SYM);
            // layer_off(_MOUSE);
            layer_move(_BASE);
            return false;
        case TILD:
            register_key_to_repeat(TILD);
            return tap_undead_key(record->event.pressed, SE_TILD);
        case CIRC:
            register_key_to_repeat(CIRC);
            return tap_undead_key(record->event.pressed, SE_CIRC);
        case NUMWORD:
            register_key_to_repeat(NUMWORD);
            process_num_word_activation(record);
            return false;
        case CAPSWORD:
            register_key_to_repeat(CAPSWORD);
            process_caps_word_activation(record);
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_escape();
                tap_code16(SE_COLN);
                tap_code(SE_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(SE_W));
                tap_code(SE_S);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(SE_W));
                tap_code(SE_V);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(SE_G));
            }
            return false;
        case AT_U:
            if (record->event.pressed) {
                tap_code16(SE_AT);
                tap16_repeatable(SE_U);
            }
            return false;
        case COLN_SYM:
            if (record->tap.count && record->event.pressed) {
                tap16_repeatable(SE_COLN);
                return false;
            }
            break;
        case KC_ENT:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_NUM)) {
                    tap16_repeatable(KC_PENT);
                } else {
                    tap16_repeatable(KC_ENT);
                }
                disable_num_word();
            }
            return false;
        case TG_SWE:
            if (record->event.pressed) {
                uint16_t swe_key = corresponding_swe_key(last_key());
                if (swe_key != KC_NO) {
                    tap_code16(KC_BSPC);
                    tap_code16(swe_key);
                }
                layer_invert(_SWE);
            }
            return false;
        case WIN_ALT:
            // Always start by sending Alt Tab to goto the next window with only a combo tap.
            // We can then do Tab/S-Tab to continue moving around the windows if we want to.
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code16(KC_TAB);
                layer_on(_WIN);
            } else {
                layer_off(_WIN);
                unregister_code(KC_LALT);
            }
            return false;
        case LEADER:
            start_leading();
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
            return false;
        case UP_DPI:
            if (record->event.pressed) {
                up_dpi();
            }
            return false;
        case DN_DPI:
            if (record->event.pressed) {
                down_dpi();
            }
            return false;
        case C_C_TAB:
            // Workaround for LCTL_T only supporting standard keycodes.
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_TAB));
                return false;
            }
            return true;
        case CA_AR:
            // Workaround for LT only supporting standard keycodes.
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(SE_A));
                return false;
            }
            return true;
        // case C_SC_TB:
        //     // Workaround for LCTL_T only supporting standard keycodes.
        //     if (record->tap.count && record->event.pressed) {
        //         tap_code16(S(C(KC_TAB)));
        //         return false;
        //     }
        //     return true;
        case SFT_CA:
            // Workaround for LSFT_T only supporting standard keycodes.
            if (record->tap.count && record->event.pressed) {
                // Send C(A) on tap
                tap_code16(C(SE_A));
                return false;
            }
            return true;
        // case XCASE_MINS:
        //     if (record->event.pressed) {
        //         enable_xcase_with(SE_MINS);
        //     }
        //     return false;
        // case XCASE_UNDS:
        //     if (record->event.pressed) {
        //         enable_xcase_with(SE_UNDS);
        //     }
        //     return false;
        // case XCASE_SHFT:
        //     if (record->event.pressed) {
        //         enable_xcase_with(OSM(MOD_LSFT));
        //     }
        //     return false;
        case SWAP_UND_MIN:
            if (record->event.pressed) {
                swap_unds_mins = !swap_unds_mins;
            }
            return false;
        case UND_MIN_MOUSE:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap16_repeatable(unds_mins_key());
                }
            } else {
                if (record->event.pressed) {
                    layer_on(_MOUSE);
                } else {
                    layer_off(_MOUSE);
                }
            }
            return false;
        case MIN_UND:
            if (record->event.pressed) {
                tap16_repeatable(mins_unds_key());
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    // If `false` was returned, then we did something special KC_SPCand should register that manually.
    // Otherwise register keyrepeat here by default.
    bool res = _process_record_user(keycode, record);

    // Space needs some special handling to not interfere with NAV toggling.
    // Maybe there's a more general way to do this, but I dunno.
    if (keycode == MT_SPC) {
        if (!record->event.pressed && last_key_down == MT_SPC) {
            register_key_to_repeat(KC_SPC);
        }
    } else if (res && record->event.pressed) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    if (record->event.pressed) {
        last_key_down = keycode;
    } else {
        last_key_up = keycode;
    }

    return res;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    debug_mouse = true;
    timer_init();
}

void pointing_device_init_user(void) {
    // set_auto_mouse_layer(_MOUSE);
    // set_auto_mouse_enable(true);
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case C(SE_A):
        case C(SE_C):
        case C(SE_X):
        case C(SE_V):
        case DN_DPI:
        case UP_DPI:
            return true;
        default:
            return false;
    }
    return is_mouse_record_user(keycode, record);
}

#define SCROLL_DIVISOR_H 10.0
#define SCROLL_DIVISOR_V 10.0

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

#define SPEED_MULTIPLIER_X 2.0
#define SPEED_MULTIPLIER_Y 2.0

float speed_accumulated_x = 0;
float speed_accumulated_y = 0;

#define PRECISION_DIVISOR_X 2.0
#define PRECISION_DIVISOR_Y 2.0

float precision_accumulated_x = 0;
float precision_accumulated_y = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    scrolling_mode = IS_LAYER_ON_STATE(state, _SYM);
    speed_mode     = IS_LAYER_ON_STATE(state, _MODS);
    precision_mode = IS_LAYER_ON_STATE(state, _NAV) || IS_LAYER_ON_STATE(state, _MOUSE);
    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // printf("Timer: %u\n", timer_elapsed(mouse_move_timer));
    // if (!IS_LAYER_ON(_MOUSE) && (mouse_report.x != 0 || mouse_report.y != 0)) {
    //     if (IS_LAYER_ON(_NAV)) {
    //         printf("Enable mouse layer\n");
    //         layer_on(_MOUSE);
    //     } else {
    //         mouse_move_timer = timer_read();
    //         // printf("Update mouse timer\n");
    //     }
    // }

    if (speed_mode) {
        speed_accumulated_x += (float)mouse_report.x * SPEED_MULTIPLIER_X;
        speed_accumulated_y += (float)mouse_report.y * SPEED_MULTIPLIER_Y;

        mouse_report.x = (int8_t)speed_accumulated_x;
        mouse_report.y = (int8_t)speed_accumulated_y;

        speed_accumulated_x -= (int8_t)speed_accumulated_x;
        speed_accumulated_y -= (int8_t)speed_accumulated_y;
    } else if (precision_mode) {
        precision_accumulated_x += (float)mouse_report.x / PRECISION_DIVISOR_X;
        precision_accumulated_y += (float)mouse_report.y / PRECISION_DIVISOR_Y;

        mouse_report.x = (int8_t)precision_accumulated_x;
        mouse_report.y = (int8_t)precision_accumulated_y;

        precision_accumulated_x -= (int8_t)precision_accumulated_x;
        precision_accumulated_y -= (int8_t)precision_accumulated_y;
    }
    if (scrolling_mode) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v -= (float)mouse_report.y / SCROLL_DIVISOR_V;

        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
