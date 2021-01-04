#pragma once

#ifdef COMBO_ENABLE

#ifdef COMB
#undef COMB
#endif

#define COMB(name, action, ...)  ##name,
enum myCombos {
#include "combos.def"
    COMBO_LENGTH
};
#undef COMB
uint16_t COMBO_LEN = COMBO_LENGTH;

#define COMB(name, action, ...)  const uint16_t PROGMEM name##_combo[] = {__VA_ARGS__, COMBO_END};
#include "combos.def"
#undef COMB

#define COMB(name, action, ...)  [##name] = COMBO(name##_combo, action),
combo_t key_combos[] = {
#include "combos.def"
};
/* int COMBO_LEN = sizeof(key_combos)/sizeof(key_combos[0]); */
#undef COMB

#endif
