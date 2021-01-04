/* vim: set fdm=marker */
/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "sevanteri.h"
#include "wrappers.h"
#include "keymap_finnish.h"
#include "pointing_device.h"
#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni_trackball.h"
# if defined(RAW_ENABLE)
# include "raw_hid.h"
# include "usb_descriptor.h"
# endif
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer {{{ */
[_BASE] = LAYOUT_gergo_wrapper(
    KC_TAB,  _________________QWERTY_L1_________________, /**/     /**/     /**/ /**/     /**/     _________________QWERTY_R1_________________, FI_QUOT,
    CTRLESC,  _________________QWERTY_L2_________________, FI_DIAE, /**/     /**/ /**/     FI_ARNG, _________________QWERTY_R2_________________, MY_AE,
    KC_LSFT, _________________QWERTY_L3_________________, _______, _______,  /**/ _______, _______, _________________QWERTY_R3_________________, KC_RSFT,
    /******/ /******/ /******/ /******/ MY_THL4, MY_THL3, MY_THL2, MY_THL1,  /**/ MY_THR1, MY_THR2, MY_THR3, MY_THR4
    ),
// }}}
/* Keymap 1: numbers and Symbols layer {{{ */
[_SYMB] = LAYOUT_gergo_wrapper(
    FI_SECT,       _________________SYMB_L1___________________, /******/   /******/ /****/ /******/ /******/ _________________SYMB_R1___________________, FI_PLUS,
    LSFT(FI_SECT), _________________SYMB_L2___________________, RALT(FI_DIAE), /**/ /****/ /******/ _______, _________________SYMB_R2___________________, LSFT(FI_PLUS),
    RALT(FI_LABK), _________________SYMB_L3___________________, _______, _______,   /****/ _______, _______, _________________SYMB_R3___________________, RALT(FI_PLUS),
    /******/       /******/ /******/ /******/            KC_NO, ___SYMB_THUMBLN_,   /****/  ___SYMB_THUMBRN_, KC_NO
    ),
// }}}
/* Keymap 2: Function layer {{{ */
[_FUNC] = LAYOUT_gergo_wrapper(
    MO(_STUF), _________________FUNCL_L1__________________, /******/ /******/ /****/ /******/ /******/ _________________FUNCL_R1__________________, KC_DEL,
    _______,  _________________FUNCL_L2__________________, KC_PGUP, /******/ /****/ /******/ _______, _________________FUNCL_R2__________________, _______,
    _______,  _________________FUNCL_L3__________________, KC_PGDN, _______, /****/ _______, _______, _________________FUNCL_R3__________________, KC_MNXT,
    /******/  /******/ /******/ /******/ KC_NO, ___FUNC_THUMBLN_,  /****/ ___FUNC_THUMBRN_, KC_NO
    ),
// }}}
/* Keymap 3: stuff {{{
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |RESET |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |CMBTOG|      |      |      |           |      |MOURST|      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[_STUF] = LAYOUT_gergo_wrapper(
    KC_TRNS, _________________STUFF_L1__________________,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_TRNS, _________________STUFF_L2__________________, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, _________________STUFF_L3__________________, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
//}}}
/* Mouse {{{ */
[_MOUS] = LAYOUT_gergo_wrapper(
    XXXXXXX, ___________________________________________,                                             KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, XXXXXXX,
    XXXXXXX, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, XXXXXXX,                           XXXXXXX, ___________________________________________, XXXXXXX,
    XXXXXXX, ___________________________________________, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, ___________________________________________, XXXXXXX,
                                        _________________________, XXXXXXX,         XXXXXXX, _______, _______, _______
    )
//   }}}
};

/* Keymap template {{{ */
/*
,[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
//   }}}
 */

#ifdef PIMORONI_TRACKBALL_ENABLE
// {{{
#include "timer.h"
#include "math.h"
#include "quantum/quantum.h"

static int16_t mouse_auto_layer_timer = 0;
#define MOUSE_TIMEOUT 600
#define TRACKBALL_TIMEOUT 5

// user config EEPROM stuff {{{
typedef union {
  uint32_t raw;
  struct {
    uint8_t tb_brightness :8;
  };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
  user_config.raw = eeconfig_read_user();
  tb_brightness = user_config.tb_brightness;
  trackball_set_brightness(tb_brightness);
}

void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.tb_brightness = 32;
  eeconfig_update_user(user_config.raw);
}
// }}}

void matrix_init_user() {
    trackball_init();
}

void suspend_power_down_user(void) {
    trackball_set_brightness(0);
    /* trackball_sleep(); */
}

__attribute__((weak)) void pointing_device_init(void) { trackball_set_rgbw(0,0,0,tb_brightness); }

void update_member(int8_t* member, int16_t* offset) {//{{{
    if (*offset > 127) {
        *member = 127;
        *offset -= 127;
    } else if (*offset < -127) {
        *member = -127;
        *offset += 127;
    } else {
        *member = *offset;
        *offset = 0;
    }
}//}}}

static int16_t x_offset = 0;
static int16_t y_offset = 0;
static int16_t v_offset = 0;
static int16_t h_offset = 0;
static int16_t tb_timer = 0;
void pointing_device_task() {
    report_mouse_t mouse = pointing_device_get_report();

    if (trackball_get_interrupt() && (!tb_timer || timer_elapsed(tb_timer) > TRACKBALL_TIMEOUT)) {
        tb_timer = timer_read() | 1;

        trackball_state_t state = trackball_get_state();

        uint8_t mods;
        if (state.raw_x || state.raw_y) {
            trigger_tapping();
            mods = get_mods();
        }

        if (state.button_triggered) {
            if(state.button_down) {
                mouse.buttons |= MOUSE_BTN1;
            } else {
                mouse.buttons &= ~MOUSE_BTN1;
            }
            pointing_device_set_report(mouse);
            pointing_device_send();
        } else {

            if (layer_state_is(_STUF)) {
                tb_brightness += state.raw_y * 4;
                trackball_set_brightness(tb_brightness | 1);

            } else if (layer_state_is(_FUNC)) {
                h_offset += state.x;
                v_offset -= state.y;

#if defined(RAW_ENABLE)
            } else if (layer_state_is(SYMB)) {
                // set volume
                uint8_t msg[RAW_EPSIZE];
                sprintf((char *)msg, "VOL:%3d ", state.y);
                raw_hid_send(msg, RAW_EPSIZE);
#endif

            } else if (state.raw_x || state.raw_y) {

                if (!mouse_auto_layer_timer && !layer_state_is(_FUNC)) {
                    layer_on(_MOUS);
                }
                mouse_auto_layer_timer = timer_read() | 1;

                float power = 3;
                if (mods & MOD_MASK_CTRL) power = 1.8;
                /* else if (mods & MOD_MASK_ALT) power = 3.2; */

                double newlen = pow(state.vector_length, power);

                x_offset += (newlen * cos(state.angle_rad));
                y_offset += (newlen * sin(state.angle_rad));

            }
        }

        /* xprintf("%d, %d, %d, %d, %d\n", */
        /*         s[0], s[1], */
        /*         s[2], s[3], */
        /*         s[4]); */

    }

    while (x_offset || y_offset || h_offset || v_offset) {
        update_member(&mouse.x, &x_offset);
        update_member(&mouse.y, &y_offset);

        update_member(&mouse.v, &v_offset);
        update_member(&mouse.h, &h_offset);

        pointing_device_set_report(mouse);
        pointing_device_send();
    }
}

void matrix_scan_user(void) {/*{{{*/
    if (mouse_auto_layer_timer && timer_elapsed(mouse_auto_layer_timer) > MOUSE_TIMEOUT) {
        report_mouse_t rep = pointing_device_get_report();
        if (rep.buttons) { return; }
        layer_off(_MOUS);
        mouse_auto_layer_timer = 0;
    }
}/*}}}*/

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {/*{{{*/
    if ((keycode < KC_BTN1 || keycode > KC_BTN5)
            && layer_state_is(_MOUS)
            && record->event.pressed) {
        layer_off(_MOUS);
        mouse_auto_layer_timer = 0;
    }
    return true;
}/*}}}*/

static uint8_t last_layer = _BASE;
layer_state_t layer_state_set_user(layer_state_t state) {/*{{{*/
    uint8_t layer = get_highest_layer(state);
    switch(layer) {
        case _SYMB:
            trackball_set_rgbw(0, 0, tb_brightness, 0);
            break;
        case _FUNC:
            trackball_set_rgbw(0, tb_brightness, 0, 0);
            break;
        case _STUF:
            trackball_set_rgbw(tb_brightness, 0, tb_brightness, 0);
            break;
        case _MOUS:
            trackball_set_rgbw(0, tb_brightness, tb_brightness, 0);
            break;
        default:
            trackball_set_rgbw(0, 0, 0, tb_brightness);
            break;
    }

    // if layer *was* STUF, save eeprom
    if (
            last_layer == _STUF
            && last_layer != layer
            && tb_brightness != user_config.tb_brightness
       ) {
        user_config.tb_brightness = tb_brightness;
        eeconfig_update_user(user_config.raw);
    }

    last_layer = layer;
    return state;
}/*}}}*/

//}}}
#endif
