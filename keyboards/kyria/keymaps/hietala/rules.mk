OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
LEADER_ENABLE = yes        # Enable leader key
TAP_DANCE_ENABLE = no      # Enable tap dance
WPM_ENABLE = yes           # Enable wpm

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = false
EXTRAKEY_ENABLE = false
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_utils.c
endif
