/**
 * LED blinking application
 */

// Include path to use is different for both targets, so these end up referring
// to different files.
#include "regmap/sim.h"
#include "regmap/port.h"
#include "regmap/gpio.h"
#include "regmap/uart.h"

#include "util/calendar.h"

#include <stdint.h>

/*
  FRDM-K64F-MAIN leds (RGB LED D12):
  PTB21 = BLUE
  PTB22 = RED
  PTE26 = GREEN (blink this)

  FRDM-K64F-SDA led:
  PTD4 = GREEN (blink this, D2)

  We could setup variance here, by doing ifdefs only once, but this is just
  experimental code. A better solution will be presented later.
*/

#if defined(IS_MAIN_MCU)
  #define LPTMR_MASK SCGC5_LPTMR

  #include "pins_k64frdm_main.h"

#elif defined(IS_SDA_MCU)
  // There is a typo on the SVD original from Keil
  // since it's based on the reference manual which also has a typo here              
  #define LPTMR_MASK SCGC5_LPTIMER
  #define PIN_ALIAS_LED PIN_SDA_LED

  #include "pins_k64frdm_sda.h"
#else
  #error "Neither IS_SDA_MCU or IS_MAIN_MCU set, AIEEEE"
#endif

#include "configuration/pins_kinetis.h"

volatile uint32_t gDummy;

// If this function returns, crt0 will cause an NVIC system reset
int main(void) {
  // 4 bit field. encoding somewhat fuzzy
  // uint32_t ramSize = (SIM->SOPT1 & SOPT1_RAMSIZE_mask) >> SOPT1_RAMSIZE_offset;
  uint32_t ramSize = SOPT1_RAMSIZE_get(SIM->SOPT1);
  uint32_t deviceID = SIM->SDID;
  (void)ramSize;
  (void)deviceID;

  volatile uint32_t now = 86400;

  Calendar nowDecomposed;
  Calendar_decompose(now, &nowDecomposed);

  uint32_t recomposed = Calendar_compose(&nowDecomposed);
  uint8_t weekday = Calendar_getDayOfWeek(now);

  gDummy = recomposed + weekday;

#if defined(IS_MAIN_MCU)
  // select RTC 32k768 oscillator as the ERCLK32K for TSI and LPTMR
  // default is zero so this is safe. We don't use this yet
  // TODO: use MASKEDSET32 here
  SIM->SOPT1 |= SOPT1_OSC32KSEL(2);
#else
  // SDA MCU does not have 32k768 ref-osc, so leave default
#endif

  // enable power to all of the PORTs (consecutive bits). we need to enable
  // power at least in order to access the registers (set the pinmux). However,
  // unknown whether power is actually required to keep static outputs or pinmux
  // settings as is (ie, power might only be required to detect changes on
  // inputs). We also power up all ports, although we only need a subset of
  // them.

  // also allow access to LPTMR (for later, not used in this program)
  // TODO: PORTE does not exist on K20 (or rather, the peripheral might actually
  //       exist there, but no pins are mapped out of the package). Should
  //       probably know this using automatically generated information.
  SIM->SCGC5 |= SCGC5_PORTA |
                SCGC5_PORTB |
                SCGC5_PORTC |
                SCGC5_PORTD |
                SCGC5_PORTE |
                LPTMR_MASK;

#if defined(IS_MAIN_MCU)

  // For the "MAIN MCU", there are three pins connected to the RGB LED that we
  // can control.
  Pin_configure(PIN_LED_RED, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);
  Pin_configure(PIN_LED_GREEN, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);
  Pin_configure(PIN_LED_BLUE, PINMUX_OUTPUT_LOW, PINMUX_FLAG_NONE);

  // Preconfigure also the two switches, although we won't be using them yet
  Pin_configure(PIN_nSW2, PINMUX_INPUT, PINMUX_FLAG_PULLUP);
  Pin_configure(PIN_nSW3, PINMUX_INPUT, PINMUX_FLAG_PULLUP);

#else // !IS_MAIN_MCU

  // Setup sane configuration for pins that are related to the K64 control in
  // any way.

  // These should be all safe, but the board design does take care of them by
  // providing somewhat safe defaults.
  // Pin_configure(PIN_nSDA_SWD_EN, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);
  // Pin_configure(PIN_nSDA_SWD_OE, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);
  // Pin_configure(PIN_nSDA_RST_TGTMCU, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);

  // For some reason this needs to be driven high for the K64 to be powered
  // though.
  Pin_configure(PIN_POWER_EN, PINMUX_OUTPUT_HIGH, PINMUX_FLAG_NONE);

  // For the "SDA MCU" we only have one LED connected pin that we can control
  // Set it up and drive to low
  Pin_configure(PIN_SDA_LED, PINMUX_OUTPUT_LOW, PINMUX_FLAG_NONE);

#endif // IS_SDA_MCU

  while (1) { 
    for (uint32_t u = 0; u < 1000000; u++) {
      // don't let compiler optimize this away nor re-arrange it. this takes
      // now significantly less time than reading from the GPIO peripheral, so
      // the frequency is slightly faster. However, we try to avoid binding our
      // code to specific peripheral instance since it might not be always
      // powered on.
      asm volatile ("nop");
    }

    // Flip a single output bit (just a write)
#if defined(IS_MAIN_MCU)
    // start with blue, but we can switch between three different leds to
    // toggle (not always while previous would be toggled off)
    static Pin toggleTarget = PIN_LED_BLUE;

    Pin_toggleOutput(toggleTarget);

    if (Pin_getInput(PIN_nSW2) == 0) {
      // switch is pressed, advance to next led
      switch (toggleTarget) {
        case PIN_LED_RED:
          toggleTarget = PIN_LED_GREEN;
          break;
        case PIN_LED_GREEN:
          toggleTarget = PIN_LED_BLUE;
          break;
        case PIN_LED_BLUE:
          toggleTarget = PIN_LED_RED;
          break;
      }
    }
#else
    Pin_toggleOutput(PIN_ALIAS_LED);
#endif
  }

  // never reached
}
