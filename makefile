#
#             LUFA Library
#     Copyright (C) Dean Camera, 2017.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

MCU          = atmega16u2
ARCH         = AVR8
BOARD        = UNO
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = universal-controller
SRC          = $(wildcard source/*.c) $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS) $(LUFA_PATH)/Drivers/Peripheral/AVR8/Serial_AVR8.c
LUFA_PATH    = libraries/LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -DUSB_CAN_BE_DEVICE -Iinclude/ 
LD_FLAGS     =

# Default target
all:

# Include LUFA-specific DMBS extension modules
DMBS_LUFA_PATH ?= $(LUFA_PATH)/Build/LUFA
include $(DMBS_LUFA_PATH)/lufa-sources.mk
include $(DMBS_LUFA_PATH)/lufa-gcc.mk

# Include common DMBS build system modules
DMBS_PATH      ?= $(LUFA_PATH)/Build/DMBS/DMBS
include $(DMBS_PATH)/core.mk
include $(DMBS_PATH)/cppcheck.mk
include $(DMBS_PATH)/doxygen.mk
include $(DMBS_PATH)/dfu.mk
include $(DMBS_PATH)/gcc.mk
include $(DMBS_PATH)/hid.mk
include $(DMBS_PATH)/avrdude.mk
include $(DMBS_PATH)/atprogram.mk


clean:
	rm -rf obj/*

flash:
	dfu-programmer atmega16u2 erase
	dfu-programmer atmega16u2 flash $(TARGET).hex
	dfu-programmer atmega16u2 reset

watch:
	gnome-terminal -x ./minicom.sh