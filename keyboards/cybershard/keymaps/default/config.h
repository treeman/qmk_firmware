// Home-row mods: https://precondition.github.io/home-row-mods#tap-hold-configuration-settings
#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
// Now the default behavior!
// #uanefine IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// Immediately turn on layer if key is pressed quickly
#define HOLD_ON_OTHER_KEY_PRESS

// Debug the device
// #define POINTING_DEVICE_DEBUG

// Connections using SPI 1
#define SPI_DRIVER SPID1
#define SPI_MISO_PIN GP12
#define PMW33XX_CS_PIN GP13
#define SPI_SCK_PIN GP14
#define SPI_MOSI_PIN GP15
// Not supported with split keyboard!
// #define POINTING_DEVICE_MOTION_PIN GP21
// The trackball is on the right
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// Important to test different values to find something that works well
#define PMW33XX_LIFTOFF_DISTANCE 0x06
// Sets the mouse resolution, up to 16000
#define PMW33XX_CPI 1600
// Reorganize
#define POINTING_DEVICE_ROTATION_270 1
#define POINTING_DEVICE_INVERT_X 1

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// Combos
#undef COMBO_TERM
#define COMBO_TERM 35
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer
#define COMBO_ONLY_FROM_LAYER 0

#define DEFAULT_XCASE_SEPARATOR SE_MINS
#define XCASE_DELIMITER_KEY SE_UNDS

// Cant import "keymap_swedish.h" as it sometimes generates extremely weird errors.
#define LEADER_ESC_KEY KC_E

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Save space
#define LAYER_STATE_16BIT
