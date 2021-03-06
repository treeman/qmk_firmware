COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no        # Keyboard RGB underglow

# Easy definition of combos
VPATH +=  keyboards/gboards/

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similar
MOUSEKEY_ENABLE = no        # Them mouse keys yo
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = no      # Disable per key RGB

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += oneshot.c
SRC += layermodes.c
SRC += casemodes.c
SRC += tap_hold.c
SRC += repeat.c
