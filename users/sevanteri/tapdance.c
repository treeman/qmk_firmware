#include QMK_KEYBOARD_H
#include "quantum.h"
#include "sevanteri.h"
#include "process_tap_dance.h"
#include "action_util.h"
#include "keymap_finnish.h"

#include "tap_dance_layer_mod_tap.c"

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
    [TD_LGUI_RABK] = ACTION_TAP_DANCE_MOD_TAP(MOD_MASK_GUI, FI_RABK),
};
