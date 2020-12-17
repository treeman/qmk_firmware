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
