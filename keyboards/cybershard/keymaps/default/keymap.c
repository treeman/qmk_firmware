// Copyright 2024 Jonas Hietala
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      // SE_J,    SE_C,    SE_Y,    SE_F,    SE_P,
      // SE_R,    SE_S,    SE_T,    SE_H,    SE_K,
      // SE_COMM, SE_V,    SE_G,    SE_D,    SE_B,
      //          SE_X,    SE_X,    SE_X,    KC_SPC
      SE_J,    SE_C,    SE_Y,    SE_F,    SE_P,         SE_X,    SE_W,    SE_O,    SE_U,    SE_DOT,
      SE_R,    SE_S,    SE_T,    SE_H,    SE_K,         SE_M,    SE_N,    SE_A,    SE_I,    SE_X,
      SE_COMM, SE_V,    SE_G,    SE_D,    SE_B,         SE_SLSH, SE_L,    SE_LPRN, SE_RPRN, SE_UNDS,
               SE_A,    SE_B,    SE_C,    KC_SPC,       SE_E,    SE_X,    SE_Y,    SE_Z
    )
};
// QK_BOOT somewhere
// clang-format on

// #include QMK_KEYBOARD_H
// #include "keymap_swedish.h"
//
// // clang-format off
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT(
//       SE_J,    SE_C,    SE_Y,    SE_F,    SE_P,         SE_X,    SE_W,    SE_O,    SE_U,    SE_DOT,
//       SE_R,    SE_S,    SE_T,    SE_H,    SE_K,         SE_M,    SE_N,    SE_A,    SE_I,    SE_X,
//       SE_COMM, SE_V,    SE_G,    SE_D,    SE_B,         SE_SLSH, SE_L,    SE_LPRN, SE_RPRN, SE_UNDS,
//       KC_NO,   SE_X,    SE_X,    SE_X,    KC_SPC,       SE_E,    SE_X,    SE_X,    SE_X,    KC_NO
//     )
// };
// clang-format on
//
// Working:
// "cols": [
//     "GP21",
//     "GP29",
//     "GP1",
//     "GP0",
//     "GP15",
//     "GP14",
//     "GP13",
//     "GP12",
//     "GP11",
//     "GP10",
//     "GP9",
//     "GP8",
//     "GP2",
//     "GP5",
//     "GP4",
//     "GP3"
// ],
// "rows": ["GP24", "GP25", "GP19", "GP16", "GP17"]
//
// My
// "matrix_pins": {
//     "cols": ["GP2", "GP3", "GP4", "GP6", "GP8"],
//     "rows": ["GP29", "GP27", "GP22", "GP23"]
// },
//
//
// {
//     "manufacturer": "Jonas Hietala",
//     "keyboard_name": "cybershard",
//     "maintainer": "Jonas Hietala",
//     "bootloader": "rp2040",
//     "diode_direction": "COL2ROW",
//     "features": {
//         "bootmagic": true,
//         "command": false,
//         "console": false,
//         "extrakey": true,
//         "mousekey": true,
//         "nkro": true
//     },
//     "matrix_pins": {
//         "cols": ["GP2", "GP3", "GP4", "GP6", "GP8"],
//         "rows": ["GP29", "GP27", "GP22", "GP23"]
//     },
//     "split": {
//         "enabled": true,
//         "soft_serial_pin": "GP0",
//         "matrix_pins": {
//             "right": {
//                 "cols": ["GP2", "GP3", "GP4", "GP6", "GP8"],
//                 "rows": ["GP29", "GP27", "GP22", "GP23"]
//             }
//         },
//         "transport": {
//             "protocol": "serial"
//         }
//     },
//     "processor": "RP2040",
//     "url": "",
//     "build": {
//         "lto": true
//     },
//     "usb": {
//         "device_version": "1.0.0",
//         "pid": "0xCF45",
//         "vid": "0xFEED"
//     },
//     "layouts": {
//         "LAYOUT": {
//             "layout": [
//                 { "matrix": [0, 0], "x": 0, "y": 0.25 },
//                 { "matrix": [0, 1], "x": 1, "y": 0.125 },
//                 { "matrix": [0, 2], "x": 2, "y": 0 },
//                 { "matrix": [0, 3], "x": 3, "y": 0.125 },
//                 { "matrix": [0, 4], "x": 4, "y": 0.25 },
//                 { "matrix": [1, 0], "x": 0, "y": 1.25 },
//                 { "matrix": [1, 1], "x": 1, "y": 1.125 },
//                 { "matrix": [1, 2], "x": 2, "y": 1 },
//                 { "matrix": [1, 3], "x": 3, "y": 1.125 },
//                 { "matrix": [1, 4], "x": 4, "y": 1.25 },
//                 { "matrix": [2, 0], "x": 0, "y": 2.25 },
//                 { "matrix": [2, 1], "x": 1, "y": 2.125 },
//                 { "matrix": [2, 2], "x": 2, "y": 2 },
//                 { "matrix": [2, 3], "x": 3, "y": 2.125 },
//                 { "matrix": [2, 4], "x": 4, "y": 2.25 },
//                 { "matrix": [3, 0], "x": 3.5, "y": 3.25 },
//                 { "matrix": [3, 1], "x": 4.5, "y": 3.5 },
//                 { "matrix": [3, 2], "x": 6.5, "y": 3.5 },
//                 { "matrix": [3, 3], "x": 7.5, "y": 3.25 },
//                 { "matrix": [3, 4], "x": 7.5, "y": 3.25 },
//
//                 { "matrix": [4, 0], "x": 0, "y": 0.25 },
//                 { "matrix": [4, 1], "x": 1, "y": 0.125 },
//                 { "matrix": [4, 2], "x": 2, "y": 0 },
//                 { "matrix": [4, 3], "x": 3, "y": 0.125 },
//                 { "matrix": [4, 4], "x": 4, "y": 0.25 },
//                 { "matrix": [5, 0], "x": 0, "y": 1.25 },
//                 { "matrix": [5, 1], "x": 1, "y": 1.125 },
//                 { "matrix": [5, 2], "x": 2, "y": 1 },
//                 { "matrix": [5, 3], "x": 3, "y": 1.125 },
//                 { "matrix": [5, 4], "x": 4, "y": 1.25 },
//                 { "matrix": [6, 0], "x": 0, "y": 2.25 },
//                 { "matrix": [6, 1], "x": 1, "y": 2.125 },
//                 { "matrix": [6, 2], "x": 2, "y": 2 },
//                 { "matrix": [6, 3], "x": 3, "y": 2.125 },
//                 { "matrix": [6, 4], "x": 4, "y": 2.25 },
//                 { "matrix": [7, 0], "x": 3.5, "y": 3.25 },
//                 { "matrix": [7, 1], "x": 4.5, "y": 3.5 },
//                 { "matrix": [7, 2], "x": 6.5, "y": 3.5 },
//                 { "matrix": [7, 3], "x": 7.5, "y": 3.25 },
//                 { "matrix": [7, 4], "x": 7.5, "y": 3.25 }
//             ]
//         }
//     }
// }
