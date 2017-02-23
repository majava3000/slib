/**
 * If data is being programmed to the start of flash area, we need to implement
 * the FlashConfig area which contains various data that the FTFE controller
 * reads after reset, some of which will make flash access impossible
 * externally.
 */

#include <stdint.h>

typedef struct {
  // backdoor comparison key (FF::FF is safe default)
  uint64_t backdoorKey;
  // program flash protection bytes (FPROT0..3) (0xFFFFFFFF is safe default)
  uint32_t fprot;
  // flash security byte (0xFE is safe default)
  uint8_t  fsec;
  // flash nonvolatile option byte (0xFF is safe default)
  // b2: NMI_DIS: If zero, NMI interrupts are always blocked. (does not affect pinmux)
  // b1: EZPORT_DIS: If zero, EzPort operation is disabled
  // b0: LPBOOT: If zero, SIM_CLKDIV1 configured with high divisors (boot at low speed)
  uint8_t  fopt;
  // EEPROM protection byte (FlexNVM devices only) (0xFF is safe default)
  uint8_t  feprot;
  // Data flash protection byte (FlexNVM devices only) (0xFF is safe default)
  uint8_t  fdprot;
} KinetisFlashConfig;

const static KinetisFlashConfig cFlashConfig __attribute__((section("flash_config"),used)) = {
  .backdoorKey = 0xFFFFFFFFFFFFFFFF,
  .fprot =  0xFFFFFFFF,
  .fsec =   0xFE,
  .fopt =   0xF9, // NMI_DIS & EZPORT_DIS cleared, LPBOOT at "normal speed" boot
  .feprot = 0xFF,
  .fdprot = 0xFF,
};
