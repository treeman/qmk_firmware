#include "encoder_utils.h"

void encoder_utils_init(void) {
    encoder_left_mode  = LENC_MODE_PAGING;
    encoder_right_mode = RENC_MODE_VOLUME;
}

void cycle_left_encoder_mode(bool reverse) {
    if (reverse) {
        if (--encoder_left_mode < 0) {
            encoder_left_mode = _LENC_MODE_LAST - 1;
        }
    } else {
        if (++encoder_left_mode == _LENC_MODE_LAST) {
            encoder_left_mode = 0;
        }
    }
}

void cycle_right_encoder_mode(bool reverse) {
    if (reverse) {
        if (--encoder_right_mode < 0) {
            encoder_right_mode = _RENC_MODE_LAST - 1;
        }
    } else {
        if (++encoder_right_mode == _RENC_MODE_LAST) {
            encoder_right_mode = 0;
        }
    }
}

void volume_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

void paging_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_PGUP);
    } else {
        tap_code(KC_PGDN);
    }
}

void alt_tab_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(A(KC_TAB));
    } else {
        tap_code16(A(S(KC_TAB)));
    }
}

void ctrl_tab_action(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(C(S(KC_TAB)));
    }
}

void action_left_encoder(bool clockwise) {
    switch (encoder_left_mode) {
        case LENC_MODE_PAGING:
            paging_action(clockwise);
            break;
        case LENC_MODE_SHIFT_TAB:
            alt_tab_action(clockwise);
            break;
        case LENC_MODE_CTRL_TAB:
            ctrl_tab_action(clockwise);
            break;
        default:
            paging_action(clockwise);
    }
}

void action_right_encoder(bool clockwise) {
    switch (encoder_right_mode) {
        case RENC_MODE_VOLUME:
            volume_action(clockwise);
            break;
        default:
            volume_action(clockwise);
    }
}
