#include "status.h"
#include "keycodes.h"
#include "casemodes.h"
#include "layermodes.h"
#include <stdio.h>

/* void render_keymap_version(void) { */
/*     oled_write_P(PSTR(KEYMAP_VERSION), false); */
/*     oled_write_ln("", false); */
/* } */

/* void render_wpm(void) { */
/*     static char wpm_str[10]; */
/*     sprintf(wpm_str, "WPM: %03d", get_current_wpm()); */
/*     oled_write_ln(wpm_str, false); */
/* } */

void render_layers(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SWE:
            oled_write_P(PSTR("Swe\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _GAME2:
            oled_write_P(PSTR("Game2\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _WNAV:
            oled_write_P(PSTR("WNav\n"), false);
            break;
        /* case _SYM: */
        /*     oled_write_P(PSTR("Sym\n"), false); */
        /*     break; */
        case _LMOD:
            oled_write_P(PSTR("Mod/Sym\n"), false);
            break;
        case _RMOD:
            oled_write_P(PSTR("Sym/Mod\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Fun\n"), false);
            break;
        case _OPT:
            oled_write_P(PSTR("Opts\n"), false);
            break;
        case _SPEC:
            oled_write_P(PSTR("Spec\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
}

void render_mod(uint8_t mods, uint8_t os_mods, uint8_t mask, char mod, char os) {
    if (mods & mask) {
        oled_write_char(mod, false);
        oled_write_char(' ', false);
    } else if (os_mods & mask) {
        oled_write_char(os, false);
        oled_write_char(' ', false);
    } else {
        oled_write_P(PSTR("  "), false);
    }
}

void render_mods(void) {
    uint8_t mods = get_mods();
    uint8_t os_mods = get_oneshot_mods();

    oled_write_P(PSTR("Mods: "), false);
    render_mod(mods, os_mods, MOD_MASK_SHIFT, 'S', 's');
    render_mod(mods, os_mods, MOD_MASK_ALT, 'A', 'a');
    render_mod(mods, os_mods, MOD_MASK_CTRL, 'C', 'c');
    render_mod(mods, os_mods, MOD_MASK_GUI, 'G', 'g');
    oled_write_ln("", false);
}

void render_nix(void) {
    oled_write_P(in_linux() ? PSTR("Nix") : PSTR("Win"), false);
    /* if (sym_word_enabled()) { */
    /*     oled_write_P(PSTR(" SymWord"), false); */
    /* } */
    if (num_word_enabled()) {
        oled_write_P(PSTR(" NumWord"), false);
    }
    oled_write_ln("", false);
}

void render_caps(void) {
    if (is_caps_swapped()) {
        oled_write_P(PSTR("(C/E swp)"), false);
    }
    bool caps_word = caps_word_enabled();
    bool xcase = xcase_enabled();
    if (caps_word && xcase) {
        oled_write_P(PSTR(" SCR_CPS"), false);
    } else if (xcase) {
        oled_write_P(PSTR(" XCASE"), false);
    } else if (caps_word) {
        oled_write_P(PSTR(" CAPSWORD"), false);
    } else if (host_keyboard_led_state().caps_lock) {
        oled_write_P(PSTR(" CAPS"), false);
    }
    oled_write_ln("", false);
}

void render_master_status(void) {
    render_layers();
    oled_write_ln("", false);
    render_mods();
    oled_write_ln("", false);
    render_nix();
    oled_write_ln("", false);
    render_caps();
    oled_write_ln("", false);
}

void render_slave_status(void) {
    /* render_keymap_version(); */
    /* oled_write_ln("", false); */
    /* render_wpm(); */
}

void render_status(void) {
    if (is_keyboard_master()) {
        render_master_status();
    } else {
        /* render_slave_status(); */
    }
}
