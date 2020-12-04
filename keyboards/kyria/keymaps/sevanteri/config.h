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

#pragma once

#define EE_HANDS

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#define PI 3.14159265358979323846
/* #define TRACKBALL_ANGLE_OFFSET PI/2 */
#define TRACKBALL_ORIENTATION 3
#define TRACKBALL_NO_MATH

#ifdef RGBLIGHT_ENABLE
  /* #define RGBLIGHT_ANIMATIONS */
  /* #define TRACKBALL_NO_MATH */
  /* #define RGBLIGHT_MODE_BREATHING */
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_DISABLE_KEYCODES
#endif

#define F_SCL 240000UL  // SCL frequency
#include "sevanteri_config.h"

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
/* #define SPLIT_USB_DETECT */
/* #define NO_USB_STARTUP_CHECK */
