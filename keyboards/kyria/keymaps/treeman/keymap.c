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
      xxxxxxx, MY_R,    MY_S,    MY_T,    MY_H,    SE_D,                                        SE_M,    MY_N,    MY_A,    MY_I,    SE_O,    xxxxxxx,
      xxxxxxx, SE_DQUO, SE_V,    SE_G,    SE_P,    SE_B,    MY_LCTL, xxxxxxx, MY_FUN,  MY_RCTL, SE_SLSH, SE_L,    SE_LPRN, SE_RPRN, SE_COMM,    xxxxxxx,
                                 L_ENCM,  SE_EQL,  MY_SPC,  MY_LSFT, KC_LEAD, KC_LEAD, MY_RSFT, MY_E,    MY_NUM,  R_ENCM
    ),
    [_NUM] = LAYOUT(
      xxxxxxx, _______, SE_6,    SE_5,    SE_4,    xxxxxxx,                                     _______, _______, _______, _______, KC_PENT, xxxxxxx,
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

