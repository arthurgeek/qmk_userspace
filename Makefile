.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(QMK_USERSPACE)/qmk_firmware

init:
	@echo "Update git submodules..."
	@git submodule sync --recursive
	@git submodule update --init --recursive --progress
	@echo "Configuring QMK CLI"
	@qmk config userspace_compile.parallel=$$(nproc 2>/dev/null)
	@qmk config user.qmk_home=$(QMK_USERSPACE)/qmk_firmware
	@qmk config user.overlay_dir=$(QMK_USERSPACE)
	@echo "Validating user space..."
	@qmk userspace-doctor

%:
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)
