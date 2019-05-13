MOUSEKEY_ENABLE = yes

#Debug options
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

SWAP_HANDS_ENABLE = no
UNICODE_ENABLE   = no  # Unicode

TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
LEADER_ENABLE = no
POINTING_DEVICE_ENABLE = yes

LTO_ENABLE = yes

#Combos!
# VPATH +=  keyboards/gboards/

# A bunch of stuff that you shouldn't touch unless you
# know what you're doing.
#
# No touchy, capiche?
SRC += matrix.c i2c_master.c
ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
