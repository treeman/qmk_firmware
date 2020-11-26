#pragma once

#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_stack_wrapper(...)            LAYOUT_stack(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_gergoplex_wrapper(...)        LAYOUT_gergoplex(__VA_ARGS__)

#define _________________QWERTY_L1_________________   MY_Q, MY_W, MY_E, MY_R, MY_T
#define _________________QWERTY_L2_________________   MY_A, MY_S, MY_D, MY_F, MY_G
#define _________________QWERTY_L3_________________   MY_Z, MY_X, MY_C, MY_V, MY_B
#define _QWERTY_L1_______________   KC_TAB,  _________________QWERTY_L1_________________
#define _QWERTY_L2_______________   CTRLESC, _________________QWERTY_L2_________________
#define _QWERTY_L3_______________   KC_LSFT, _________________QWERTY_L3_________________

#define _________________QWERTY_R1_________________   MY_Y, MY_U, MY_I,    MY_O,   MY_P
#define _________________QWERTY_R2_________________   MY_H, MY_J, MY_K,    MY_L,   MY_OE
#define _________________QWERTY_R3_________________   MY_N, MY_M, MY_COMM, MY_DOT, MY_MINS
#define _______________QWERTY_R1_   _________________QWERTY_R1_________________, FI_QUOT
#define _______________QWERTY_R2_   _________________QWERTY_R2_________________, MY_AE
#define _______________QWERTY_R3_   _________________QWERTY_R3_________________, KC_RSFT


#define _________________SYMB_L1___________________   KC_1,       KC_2,       KC_3,       KC_4,       KC_5
#define _________________SYMB_L2___________________   LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5)
#define _________________SYMB_L3___________________   _______,    RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5)
#define  _SYMB_L1_________________  LSFT(FI_SECT),  _________________SYMB_L1___________________
#define  _SYMB_L2_________________  FI_SECT,        _________________SYMB_L1___________________
#define  _SYMB_L3_________________  RALT(FI_SECT),  _________________SYMB_L3___________________

#define _________________SYMB_R1___________________   KC_6,       KC_7,       KC_8,       KC_9,       KC_0
#define _________________SYMB_R2___________________   LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0)
#define _________________SYMB_R3___________________   _______,    RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0)
#define _________________SYMB_R1_   _________________SYMB_R1___________________, LSFT(FI_PLUS)
#define _________________SYMB_R2_   _________________SYMB_R1___________________, FI_PLUS
#define _________________SYMB_R3_   _________________SYMB_R3___________________, RALT(FI_PLUS)


#define _________________FUNCL_L1__________________   KC_F1, KC_F2,  KC_F3,  KC_F4,  _______
#define _________________FUNCL_L2__________________   KC_F5, KC_F6,  KC_F7,  KC_F8,  _______
#define _________________FUNCL_L3__________________   KC_F9, KC_F10, KC_F11, KC_F12, _______

#define _________________FUNCL_R1__________________   KC_WBAK, CTRLTAB, CSFTTAB, KC_WFWD, KC_VOLU
#define _________________FUNCL_R2__________________   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD
#define _________________FUNCL_R3__________________   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MPLY


#define _________________MOUS_R1___________________   KC_BTN2, KC_BTN3, _______, _______, _______
#define _________________MOUS_R2___________________   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______
#define _________________MOUS_R3___________________   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______


#define _________________STUFF_L1__________________   TB_B_UP, _______, EEP_RST, RESET,   _______
#define _________________STUFF_L2__________________   TB_B_DN, _______, _______, _______, _______
#define _________________STUFF_L3__________________   _______, _______, CMB_TOG, _______, _______

#define ___________________________________________   _______, _______, _______, _______, _______
#define          __________________________________   _______, _______, _______, _______
#define                   _________________________   _______, _______, _______
#define                            ________________   _______, _______



#define ____QWERTY_L4___    MY_THL4,  MY_THL3
#define ____SYMB_L4_____    _______,  CODEBLK
#define ____FUNC_L4_____    _______,  MO(_STUF)


#define ____QWERTY_R4___    MY_THR3,  PSCRINS
#define ____SYMB_R4_____    _______,  SE_ACUT
#define ____FUNC_R4_____    _______,  KC_RALT
#define ____MOUS_R4_____    KC_BTN3,  _______

#define _QWERTY_THUMBLN_    MY_THL1,   MY_THL2,  MY_THL3
#define ___SYMB_THUMBLN_    CODEBLK,   KC_DOT,   _______
#define ___FUNC_THUMBLN_    MO(_STUF),  _______,  KC_DEL
#define ___MOUS_THUMBLN_    _______,   _______,  _______

#define _QWERTY_THUMBRN_    MY_THR3, MY_THR2, MY_THR1
#define ___SYMB_THUMBRN_    _______, _______, _______
#define ___FUNC_THUMBRN_    _______, _______, _______
#define ___MOUS_THUMBRN_    KC_BTN1, _______, _______


// old ones (ergodox)
#define _QWERTY_THUMBL__    MY_THL2, MY_THL1
#define ___SYMB_THUMBL__    KC_DOT,  _______
#define ___FUNC_THUMBL__    _______, KC_DEL

#define _QWERTY_THUMBR__    MY_THR1, MY_THR2
#define ___SYMB_THUMBR__    _______, _______
#define ___FUNC_THUMBR__    _______, _______
#define ___MOUS_THUMBR__    KC_BTN1, KC_BTN2
