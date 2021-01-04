#include "oled_utils.h"
#include "encoder_utils.h"
#include "status.h"
#include <stdio.h>

void render_keymap_version(void) {
    oled_write_P(PSTR(KEYMAP_VERSION), false);
    oled_write_ln("", false);
}

#ifdef ENCODER_ENABLE
void render_left_rotary_state(void) {
    oled_write_P(PSTR("Enc: "), false);
    switch (encoder_left_mode) {
        case LENC_MODE_PAGING:
            oled_write_P(PSTR("Paging\n"), false);
            break;
        case LENC_MODE_SHIFT_TAB:
            oled_write_P(PSTR("Shift Tab\n"), false);
            break;
        case LENC_MODE_CTRL_TAB:
            oled_write_P(PSTR("Ctrl Tab\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
            break;
    }
}
#endif

void render_wpm(void) {
    static char wpm_str[10];
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_ln(wpm_str, false);
}

void render_layers(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        case _MISC:
            oled_write_P(PSTR("Misc\n"), false);
            break;
        case _MOVE:
            oled_write_P(PSTR("Move\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}

void render_mods(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_write_P(PSTR("Mods: "), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S ") : PSTR("  "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G ") : PSTR("  "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C ") : PSTR("  "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A ") : PSTR("  "), false);

    /* static char mod_str[10]; */
    /* sprintf(mod_str, "\nRAW: %03d", modifiers); */
    /* oled_write(mod_str, false); */

    oled_write_ln("", false);
}

void render_caps(void) {
    uint8_t led_usb_state = host_keyboard_leds();
    if (IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR("CAPS "), false);
    }
    if (swap_caps_escape) {
        oled_write_P(PSTR("(Swapped ESC)"), false);
    }
    // TODO Render swapped ESC/CAPS status
    oled_write_ln("", false);

    // Host Keyboard LED Status
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false); */
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false); */
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false); */
}

void render_master_status(void) {
    render_keymap_version();
    oled_write_ln("", false);
#ifdef ENCODER_ENABLE
    render_left_rotary_state();
    oled_write_ln("", false);
#endif
    render_wpm();
}

void render_slave_status(void) {
    render_layers();
    oled_write_ln("", false);
    render_mods();
    oled_write_ln("", false);
    render_caps();
    oled_write_ln("", false);
    render_wpm();
}

void render_status(void) {
    if (is_keyboard_master()) {
        render_master_status();
    } else {
        render_slave_status();
    }
}
