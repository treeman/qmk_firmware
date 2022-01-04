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

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DISABLE_KEYCODES
    #define RGBLIGHT_LAYERS
#endif

// Home-row mods: https://precondition.github.io/home-row-mods#tap-hold-configuration-settings
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM_PER_KEY
#ifdef TAPPING_TERM_PER_KEY
#define TAPPING_TERM 170
#else
// Only for thumbs
#define TAPPING_TERM 220
#endif

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// Immediately turn on layer if key is pressed quickly
#define HOLD_ON_OTHER_KEY_PRESS

// Combos
#undef COMBO_TERM
#define COMBO_TERM 35
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space
#define COMBO_ONLY_FROM_LAYER 0

#define DEFAULT_XCASE_SEPARATOR SE_MINS
#define XCASE_DELIMITER_KEY SE_UNDS

// Cannot import "keymap_swedish.h" as it sometimes generates extremely weird errors.
#define LEADER_ESC_KEY KC_E

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Save space
//#define LAYER_STATE_8BIT
#define LAYER_STATE_16BIT
// These are a bit iffy, as I don't know what they're doing, but it "works fine" according to Discord people
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE
