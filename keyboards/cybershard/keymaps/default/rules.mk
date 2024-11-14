COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes

# Easy definition of combos
VPATH +=  keyboards/gboards/

# Keylogging and debugging
CONSOLE_ENABLE = yes

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similar
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = no

# Saves a bunch of memory
EXTRAFLAGS += -flto
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += oneshot.c
SRC += layermodes.c
SRC += casemodes.c
SRC += tap_hold.c
SRC += repeat.c
SRC += leader.c

