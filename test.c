/**
 * LED blinking application
 */

// Include path to use is different for both targets, so these end up referring
// to different files.
#include "regmap/sim.h"
#include "regmap/port.h"
#include "regmap/gpio.h"

// Not generated currently by regmap generator
#define SIM_SOPT1_OSC32KSEL(n) \
  (((n) << SIM_SOPT1_OSC32KSEL_offset) & SIM_SOPT1_OSC32KSEL_mask)

// The weird cast below is required to force gcc to issue a full width write
// to the PCR register (even as declared volatile uint32_t). Voodoo.
#define PORT_PCR_MUX(n) \
  ((uint32_t)(((n) << PORT_PCR_MUX_offset) & PORT_PCR_MUX_mask))

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
  #define LPTMR_MASK SIM_SCGC5_LPTMR_mask
  #define BLINK_GPIO GPIOB
  #define BLINK_PIN  21
#elif defined(IS_SDA_MCU)
  // There is a typo on the SVD original from Keil
  // since it's based on the reference manual which also has a typo here              
  #define LPTMR_MASK SIM_SCGC5_LPTIMER_mask
  #define PIN_ALIAS_LED PIN_SDA_LED

  #include "pins_k64frdm_sda.h"
#else
  #error "Neither IS_SDA_MCU or IS_MAIN_MCU set, AIEEEE"
#endif

#include "configuration/pins_kinetis.h"

// If this function returns, crt0 will cause an NVIC system reset
int main(void) {
  // 4 bit field. encoding somewhat fuzzy
  uint32_t ramSize = (SIM->SOPT1 & SIM_SOPT1_RAMSIZE_mask) >> SIM_SOPT1_RAMSIZE_offset;
  uint32_t deviceID = SIM->SDID;
  (void)ramSize;
  (void)deviceID;

#if defined(IS_MAIN_MCU)
  // select RTC 32k768 oscillator as the ERCLK32K for TSI and LPTMR
  // default is zero so this is safe. We don't use this yet
  SIM->SOPT1 |= SIM_SOPT1_OSC32KSEL(2);
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
  SIM->SCGC5 |= SIM_SCGC5_PORTA_mask |
                SIM_SCGC5_PORTB_mask |
                SIM_SCGC5_PORTC_mask |
                SIM_SCGC5_PORTD_mask |
                SIM_SCGC5_PORTE_mask |
                LPTMR_MASK;

#if defined(IS_MAIN_MCU)

  // For the "MAIN MCU", there are three pins connected to the RGB LED that we
  // can control.

  // Select direction of the relevant GPIO pins as output
  GPIOB->PDDR |= (1 << 21) | (1 << 22);
  GPIOE->PDDR |= (1 << 26);
  // Drive all high (set bits which are selected by given masks)
  GPIOB->PSOR = (1 << 21) | (1 << 22);
  GPIOE->PSOR = (1 << 26);
  // Except for the one that we'll leave on
  BLINK_GPIO->PCOR = (1 << BLINK_PIN);

  // Select GPIO function in the pinmuxes for all LED pins
  // shortcut: PORTB->GPCHR = (1 << 22) | (1 << 21) | (1 << PORT_PCR_MUX_offset)
  PORTB->PCR[21] = PORT_PCR_MUX(1);
  PORTB->PCR[22] = PORT_PCR_MUX(1);
  PORTE->PCR[26] = PORT_PCR_MUX(1);

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
    BLINK_GPIO->PTOR = (1 << BLINK_PIN);
#else
    Pin_toggleOutput(PIN_ALIAS_LED);
#endif
  }

  // never reached
}
