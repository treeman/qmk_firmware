#include QMK_KEYBOARD_H
#include "quantum.h"
#include "sevanteri.h"
#include "process_tap_dance.h"
#include "action_util.h"
#include "keymap_finnish.h"

enum { REST, HOLD1, HOLD2, HOLD3 };

static int HomeEndMod = REST;
void modFinish(qk_tap_dance_state_t* state, void* user_data) {
	switch (state->count) {
		case 1:
			if (state->pressed) {
				register_code(KC_LCTL);
				HomeEndMod = HOLD1;
			} else {
				tap_code(KC_HOME);
			}
			break;
		case 2:
			if (state->pressed) {
				register_code(KC_LSFT);
				HomeEndMod = HOLD2;
			} else {
				tap_code(KC_END);
			}
			break;
		default:
			reset_tap_dance(state);
			break;
	}
}

void modReset(qk_tap_dance_state_t* state, void* user_data) {
	switch (HomeEndMod) {
		case HOLD1:
			unregister_code(KC_LCTL);
			break;
		case HOLD2:
			unregister_code(KC_LSFT);
			break;
	}
	HomeEndMod = REST;
}

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

#define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) \
        { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void*)user_user_data, }

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_HOME_END]     = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
  [TD_PSCR_INS]     = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, KC_INS),
  [TD_HOME_END_MOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, modFinish, modReset),
  [TD_SEEND_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_DOT),
  [TD_SEEND_QUES] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_QUES),
  [TD_SEEND_EXLM] = ACTION_TAP_DANCE_FN_ADVANCED_USER(sentence_end_tap, sentence_end_fin, NULL, FI_EXLM),
};
