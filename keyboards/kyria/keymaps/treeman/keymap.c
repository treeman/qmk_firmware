/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "status.h"

#include "keymap_swedish.h"
#include "sendstring_swedish.h"

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled_utils.h"
#endif

bool inside_leader;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Modified RSTHD
 */
    [_BASE] = LAYOUT(
      xxxxxxx, SE_K,    SE_C,    SE_Y,    SE_F,    SE_J,                                        SE_X,    SE_W,    SE_COLN, SE_U,    SE_DOT,  xxxxxxx,
      xxxxxxx, MY_R,    MY_S,    MY_T,    MY_H,    SE_D,                                        SE_M,    MY_N,    MY_A,    MY_I,    MY_O,    xxxxxxx,
      xxxxxxx, SE_SLSH, SE_V,    SE_G,    SE_P,    SE_B,    xxxxxxx, MY_LCTL, MY_RCTL, xxxxxxx, SE_COMM, SE_L,    SE_RPRN, SE_LPRN, SE_UNDS, xxxxxxx,
                                 L_ENCM,  KC_LEAD, xxxxxxx, MY_SPC,  MY_LSFT, MY_RSFT, MY_E,    MY_NUM,  KC_LEAD, R_ENCM
    ),
    [_SWE] = LAYOUT(
      xxxxxxx, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, SE_ODIA, xxxxxxx,
      xxxxxxx, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_ARNG, SE_ADIA, _______, xxxxxxx,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
    ),
    [_NUM] = LAYOUT(
      xxxxxxx, _______, SE_6,    SE_5,    SE_4,    _______,                                     _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, SE_3,    SE_2,    SE_1,    SE_0,    xxxxxxx,                                     _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, xxxxxxx, SE_9,    SE_8,    SE_7,    xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT(
      xxxxxxx, _______, KC_F6,   KC_F5,   KC_F4,   KC_F12,                                      _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, KC_F3,   KC_F2,   KC_F1,   xxxxxxx, KC_F11,                                      _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, xxxxxxx, KC_F9,   KC_F8,   KC_F7,   KC_F10,  _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
    /*
    [_BLANK] = LAYOUT(
      xxxxxxx, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, xxxxxxx,
      xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, xxxxxxx,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ 
    ),
    */
};

#define THUMB_TERM 20
#define INDEX_TERM -20
#define MIDDLE_TERM 0
#define RING_TERM 50
#define PINKY_TERM 100

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_SPC:
        case MY_E:
            return TAPPING_TERM + THUMB_TERM;
        case MY_H:
        case MY_N:
            return TAPPING_TERM + INDEX_TERM;
        case MY_T:
        case MY_A:
            return TAPPING_TERM + MIDDLE_TERM;
        case MY_S:
        case MY_I:
            return TAPPING_TERM + RING_TERM;
        case MY_R:
        case MY_O:
            return TAPPING_TERM + PINKY_TERM;
        default:
            return TAPPING_TERM;
    }
}

// Swedish symbols from base
// ) -> Å
const key_override_t base_arng_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_RPRN, SE_ARNG, ~(1 << _SWE), MOD_MASK_AG);
// ( -> Ä
const key_override_t base_adia_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_LPRN, SE_ADIA, ~(1 << _SWE), MOD_MASK_AG);
// . -> Ö
const key_override_t base_odia_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_DOT, SE_ODIA, ~(1 << _SWE), MOD_MASK_AG);

// Go back to symbols on the swedish layer
// Å -> )
const key_override_t swe_arng_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_ARNG, SE_RPRN, 1 << _SWE, MOD_MASK_AG);
// Ä -> )
const key_override_t swe_adia_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_ADIA, SE_LPRN, 1 << _SWE, MOD_MASK_AG);
// Ö -> .
const key_override_t swe_odia_override = ko_make_with_layers_and_negmods(MOD_MASK_CTRL, SE_ODIA, SE_DOT, 1 << _SWE, MOD_MASK_AG);

// : -> ?
const key_override_t coln_override = ko_make_basic(MOD_MASK_SHIFT, SE_COLN, SE_QUES);
// . -> %
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, SE_DOT, SE_PERC);
// / -> !
const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, SE_SLSH, SE_EXLM);
// , -> &
const key_override_t comm_override = ko_make_basic(MOD_MASK_SHIFT, SE_COMM, SE_AMPR);
// ) -> #
const key_override_t rprn_override = ko_make_basic(MOD_MASK_SHIFT, SE_RPRN, SE_HASH);
// ( -> *
const key_override_t lprn_override = ko_make_basic(MOD_MASK_SHIFT, SE_LPRN, SE_ASTR);
// _ -> ~
// FIXME this doesn't register
const key_override_t unds_override = ko_make_basic(MOD_MASK_SHIFT, SE_UNDS, MY_TILD);

/*  */
/* // FIXME  this doesn't work either :( */
/* bool send_tild(bool key_down, void *args) { */
/*     if (key_down) { */
/*         SEND_STRING("~"); */
/*     } */
/*  */
/*     return false; */
/* } */
/*  */
/* const key_override_t unds_override = { */
/*     .trigger_modifiers = MOD_MASK_SHIFT, */
/*     .layers = 0, */
/*     .suppressed_mods = MOD_MASK_SHIFT, */
/*     .options = ko_options_default, */
/*     .negative_modifier_mask = MOD_MASK_CAG, */
/*     .custom_action = send_tild, */
/*     .context = NULL, */
/*     .trigger = SE_UNDS, */
/*     .replacement = SE_UNDS, */
/*     .enabled = NULL */
/* }; */

const key_override_t **key_overrides = (const key_override_t *[]){
    &base_arng_override,
    &base_adia_override,
    &base_odia_override,
    &swe_arng_override,
    &swe_adia_override,
    &swe_odia_override,
    &coln_override,
    &dot_override,
    &slsh_override,
    &comm_override,
    &rprn_override,
    &lprn_override,
    &unds_override,
    NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef ENCODER_ENABLE
        case L_ENCM:
            if (record->event.pressed) {
                cycle_left_encoder_mode(false);
            }
            break;
        case R_ENCM:
            if (record->event.pressed) {
                cycle_right_encoder_mode(false);
            }
            break;
#endif
    case KC_ESC:
      if (swap_caps_escape && !inside_leader) {
        if (record->event.pressed) {
            register_code(KC_CAPS);
        } else {
            unregister_code(KC_CAPS);
        }
        return false;
      }
      return true;
    case KC_CAPS:
      if (swap_caps_escape && !inside_leader) {
        if (record->event.pressed) {
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
      }
      return true;
    case MY_TILD:
      // FIXME even this doesn't work
      if (record->event.pressed) {
          register_code(SE_DOT);
      } else {
          unregister_code(SE_DOT);
      }
      return true;

      SEND_STRING("~");
      return false;
    /* case TO_BASE: */
    /*   layer_clear(); */
    /*   clear_oneshot_mods(); */
    /*   return false; */
    /* case MY_GRV: */
    /*   SEND_STRING("`"); */
    /*   return false; */
    /* case MY_CIRC: */
    /*   SEND_STRING("^"); */
    /*   return false; */
    /* case MY_TILD: */
    /*   SEND_STRING("~"); */
    /*   return false; */
    /* case SE_DOT: */
    /*   // . -> ! */
    /*   if (remap_shift(record, SE_1, 0)) return false; */
    /*   return true; */
    /* case SE_COMM: */
    /*   // , -> ? */
    /*   if (remap_shift(record, SE_PLUS, 1)) return false; */
    /*   return true; */
    /* case MY_SPACE: */
    /*   // space -> / */
    /*   if (remap_shift(record, SE_7, 2)) return false; */
    /*   return true; */
    /* case SE_COLN: */
    /*   // : -> % */
    /*   if (remap_shift(record, SE_5, 3)) return false; */
    /*   return true; */
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_task_user(void) {
    render_status();
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        action_left_encoder(clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    } else if (index == 1) {
        action_right_encoder(clockwise);
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
    }
}
#endif

void swap_caps_esc(void) {
    swap_caps_escape = !swap_caps_escape;
#   ifdef OLED_DRIVER_ENABLE
        oled_on();
#   endif
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(SE_C, SE_C) {
      if (swap_caps_escape) {
        tap_code(KC_ESC);
      } else {
        tap_code(KC_CAPS);
      }
    }

    SEQ_ONE_KEY(KC_ESC) {
        swap_caps_esc();
    }
    SEQ_ONE_KEY(KC_CAPS) {
        swap_caps_esc();
    }
  }
}

void leader_start(void) {
    inside_leader = true;
}

void leader_end(void) {
    inside_leader = false;
}

