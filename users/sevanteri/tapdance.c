#include QMK_KEYBOARD_H
#include "quantum.h"
#include "sevanteri.h"
#include "process_tap_dance.h"
#include "action_util.h"
#include "keymap_finnish.h"

void sentence_end_tap(qk_tap_dance_state_t *state, void *user_data) {
    tap_code16((int16_t)((size_t)user_data));
}
void sentence_end_fin(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        // Double tapping produces
        // "<key> <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_BSPC);
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
            }
            break;
    }
};


void tapRelease(qk_tap_dance_state_t* state, void* user_data) {
    state->finished = true;
}

typedef struct {
    uint16_t keycode;
    uint8_t mods;
    bool held;
} mod_tap_t;
void mtFin(qk_tap_dance_state_t* state, void* user_data) {
    mod_tap_t *data = (mod_tap_t*)user_data;
    if (state->pressed) {
        data->held = true;
        register_mods(data->mods);
    }
}
void mtReset(qk_tap_dance_state_t* state, void* user_data) {
    mod_tap_t *data = (mod_tap_t*)user_data;
    if (data->held) {
        data->held = false;
        unregister_mods(data->mods);
    } else {
        tap_code16(data->keycode);
    }
}
#define ACTION_TAP_DANCE_MOD_TAP(_mods, _keycode) \
    { .fn = {NULL, mtFin, mtReset, tapRelease}, .user_data = (void*)&((mod_tap_t){.keycode=_keycode, .mods=_mods})}


typedef struct {
    uint16_t keycode;
    uint8_t layer;
    bool held;
} layer_tap_t;
void ltFin(qk_tap_dance_state_t* state, void* user_data) {
    layer_tap_t *data = (layer_tap_t*)user_data;
    if (state->pressed) {
        data->held = true;
        layer_on(data->layer);
    }
}
void ltReset(qk_tap_dance_state_t* state, void* user_data) {
    layer_tap_t *data = (layer_tap_t*)user_data;
    if (data->held) {
        data->held = false;
        layer_off(data->layer);
    } else {
        tap_code16(data->keycode);
    }
}
#define ACTION_TAP_DANCE_LAYER_TAP(_layer, _keycode) \
    { .fn = {NULL, ltFin, ltReset, tapRelease}, .user_data = (void*)&((layer_tap_t){.keycode=_keycode, .layer=_layer})}


#define ACTION_TAP_DANCE_FN_ADVANCED_USER(on_tap, on_finished, on_reset, user_user_data) \
        { .fn = {on_tap, on_finished, on_reset}, .user_data = (void*)user_user_data, }
qk_tap_dance_action_t tap_dance_actions[] = {
  /* [TD_HOME_END]     = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END), */
  /* [TD_PSCR_INS]     = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, KC_INS), */
  /* [TD_SEEND_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_DOT), */
  /* [TD_SEEND_QUES] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_QUES), */
  /* [TD_SEEND_EXLM] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_EXLM), */
    [TD_FUNC_DQUOTES] = ACTION_TAP_DANCE_LAYER_TAP(_FUNC, FI_DQUO),
    [TD_LCTL_SLASH] = ACTION_TAP_DANCE_MOD_TAP(MOD_MASK_CTRL, FI_SLSH),
};
