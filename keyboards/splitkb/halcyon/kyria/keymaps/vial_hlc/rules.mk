VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes

ENCODER_MAP_ENABLE = no

# This adds module functionality to your keyboard (files found in users/halcyon_modules)
USER_NAME := halcyon_modules

# Add custom 20-point font
SRC += keyboards/splitkb/halcyon/kyria/keymaps/vial_hlc/graphics/fonts/Retron2000-20.qff.c

# Display code
SRC += keyboards/splitkb/halcyon/kyria/keymaps/vial_hlc/display.c

# RGB code
SRC += keyboards/splitkb/halcyon/kyria/keymaps/vial_hlc/rgb.c

# Shared user code for Portuguese characters and layers
VPATH += $(USER_PATH)/../arthurzapparoli
SRC += $(USER_PATH)/../arthurzapparoli/portuguese.c
