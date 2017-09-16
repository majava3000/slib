##
# This quite horrific hack for now builds both targets simultaneously
# Same section addresses and initial SP are used for both, and we're lucky to
# manage this. Just ignore the make (I know the dependencies are not perfect)
##

# Support for separate debug symbols removed

# Disable implicit functionality
.SUFFIXES:
MAKEFLAGS += -rR

##
# CONFIGURATION
##

testbinarylist := k64frdm-main k64frdm-sda
# prefer srec instead of ihex, since JLink can't handle ihex suffix and functionality is same
targets := $(foreach basename,$(testbinarylist),$(basename).elf $(basename).bin $(basename).srec $(basename).lst)
#targets += test_calendar

# TODO: For some reason ?= doesn't work here
CC := arm-none-eabi-gcc
OBJCOPY := $(subst -gcc,-objcopy,$(CC))
OBJDUMP := $(subst -gcc,-objdump,$(CC))
CP := cp
RM := rm -f

PATH_CMSIS := vendor/CMSIS/CMSIS

makeTargetIncludeList = $(PATH_CMSIS) registermap/arm/$(1)
expandIncludes = $(foreach path,$(call makeTargetIncludeList,$(1)),-I$(path))

INCLUDES_SDA := $(call expandIncludes,kinetis/mk20d5)
INCLUDES_MAIN := $(call expandIncludes,kinetis/mk64f12)

# TODO: We should get most of these settings from the chip directory
CPU_FLAGS := -mcpu=cortex-m3 -march=armv7-m -mthumb $(CPU_FLAGS)
# TODO: This will also work on the K20 (just, this is the maximum, since the 16K
#       is split evently into SRAM_L and SRAM_U.
STACK_TOP ?= 0x20002000
PATH_LINKER_SCRIPT ?= simple.ld

# Using lowercase d here would be better, since we're not interested in disasm
# of the debug section, since it only contains the same stuff again (kind of).
# However, we do want flash_config and vectors, for content dump at least and
# this seems the only way (binutils objdump doesn't allow specifying which
# sections should be dumped).
DISSASSEMBLY_OPTIONS := --disassembler-options=reg-names-std -hDSw
# You might want to use -Os later
OPTIMIZATION_FLAGS := -Og -g -ggdb $(OPTIMIZATION_FLAGS)
WARNING_FLAGS := -Wall $(WARNING_FLAGS)

##
# SETUP
##

ORIG_CFLAGS := $(CFLAGS)
# must be recursive to work with automatic variables
CFLAGS = $(CPU_FLAGS) $(OPTIMIZATION_FLAGS) $(WARNING_FLAGS) $(INCLUDES) $(ORIG_CFLAGS)

ORIG_LDFLAGS := $(LDFLAGS)
# ditto here
LDFLAGS = -nostdlib -nostartfiles -ffreestanding \
          -T $(PATH_LINKER_SCRIPT) \
          -Wl,-Map=$(basename $(basename $(notdir $@))).map \
          -Wl,--cref \
          -Wl,--build-id=none \
          -Wl,--gc-sections \
          -Wl,--defsym -Wl,__stack_top=$(STACK_TOP) \
          $(ORIG_LDFLAGS)

##
# RULE TEMPLATES
##

GENERIC_CC = $(CC) $(CFLAGS) -c $(filter %.c,$<) -o $@
GENERIC_LD = $(CC) $(LDFLAGS) $(filter %.o,$^) -o $@
# Creates simple hex containers, based on target suffix
GENERIC_MKHEX = $(OBJCOPY) -O $(patsubst .%,%,$(suffix $@)) $< $@ && chmod -x $@

##
# RULES
##

all: $(targets)
.PHONY: all

$(targets): GNUmakefile

# We can reuse these both, just. Both have compatible FTPROT sections and
# minimal vector area. init0.o must come before crt0.o. Otherwise linker will
# fulfill the weak symbol from within crt0, since it's also implemented there,
# and even if a strong symbol comes later in the linking order, it won't be
# used. Back in the 1980s, the one-object-at-a-time -linking strategy must've
# seemed like a good an efficient way of doing things. Sigh.
KINETIS_CRT_OBJECTS := init0.o crt0.o flashconfig.o pins_kinetis.o
# Test calendar building for embedded
#KINETIS_CRT_OBJECTS += util/calendar.o

# test_calendar: test_calendar.c util/calendar.c
# 	cc -Wall $(filter %.c,$^) -o $@

%.o: %.c
	$(GENERIC_CC)

crt0.o: INCLUDES=-I$(PATH_CMSIS)
crt0.o: configuration/chip.h cmsis.h irqn.h

util/calendar.o: util/calendar.h

k64frdm-main-test.o: INCLUDES=$(INCLUDES_MAIN)
k64frdm-main-test.o: CFLAGS+=-DIS_MAIN_MCU=1
k64frdm-main-test.o: test.c
	$(GENERIC_CC)

k64frdm-sda-test.o: INCLUDES=$(INCLUDES_SDA)
k64frdm-sda-test.o: CFLAGS+=-DIS_SDA_MCU=1
k64frdm-sda-test.o: test.c
	$(GENERIC_CC)

k64frdm-main.elf: k64frdm-main-test.o $(KINETIS_CRT_OBJECTS) $(PATH_LINKER_SCRIPT)
	$(GENERIC_LD)

k64frdm-sda.elf: k64frdm-sda-test.o $(KINETIS_CRT_OBJECTS) $(PATH_LINKER_SCRIPT)
	$(GENERIC_LD)

%.lst: %.elf
	$(OBJDUMP) $(DISSASSEMBLY_OPTIONS) $< > $@

%.bin: %.elf
	$(OBJCOPY) -O binary --gap-fill=0xFF $< $@
	chmod -x $@

%.ihex: %.elf
	$(GENERIC_MKHEX)

%.srec: %.elf
	$(GENERIC_MKHEX)


##
# UTILITIES
##

clean:
	$(RM) $(targets) $(wildcard *.o) $(wildcard util/*.o) $(wildcard *.map)
.PHONY: clean
