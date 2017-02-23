MK20DX128VFM5 is present on the FRDM-K64M board as the "CMSIS-DAP" processor.

MK20D?[0-9]*VFM5:
 CM4 (revision unknown), no FPU, 32QFN, MaxFreq 50MHz, 20 GPIO
 SRAM_L aand SRAM_U, split across 2000.0000? evenly (yes, page 90 has
 the picture about this). upper region bitband capable (but only upper).
 K20 retains only SRAM_U in VLLS2 (which is interesting)
 Note that both SRAMs have separate ports to the cross-switch, so yes,
 still we prefer a split between the two to accelerate code if required.

MK20DN = No FlexNVM (no emulated EEPROM)
MK20DX = Extra 32K Flash to emulate 2K EEPRON (at 0x1000.0000 - 14ff.ffff)

N32=32KiB Flash, 8KiB SRAM
X32=32KiB Flash, 8KiB SRAM, 2KiB EMUPROM
N64=64KiB Flash, 16KiB SRAM
X64=64KiB Flash, 16KiB SRAM, 2KiB EMUPROM
N128=128KiB Flash, 16KiB SRAM
X128=128KiB Flash, 16KiB SRAM, 2KiB EMUPROM
