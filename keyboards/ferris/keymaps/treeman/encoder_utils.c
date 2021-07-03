#include "encoder_utils.h"
#include "status.h"

void volume_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLD);
    } else {
        tap_code(KC_VOLU);
    }
}

void tab_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(S(KC_TAB));
    } else {
        tap_code16(KC_TAB);
    }
}

void ctrl_tab_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(S(KC_TAB)));
    } else {
        tap_code16(C(KC_TAB));
    }
}

void undo_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(S(SE_Z)));
    } else {
        tap_code16(C(SE_Z));
    }
}

void action_left_encoder(bool clockwise) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    // Windows alt+tab, alt+shift+tab toggling
    if (modifiers & MOD_MASK_ALT) {
        tab_action(clockwise);
        return;
    }

    ctrl_tab_action(clockwise);
}

void action_right_encoder(bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _NAV:
            undo_action(clockwise);
        default:
            volume_action(clockwise);
    }
}
