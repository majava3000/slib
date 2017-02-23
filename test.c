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
  #define BLINK_GPIO GPIOD
  #define BLINK_PIN  4
#else
  #error "Neither IS_SDA_MCU or IS_MAIN_MCU set, AIEEEE"
#endif

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

  // For the "SDA MCU" we only have one LED connected pin that we can control

  // Select direction of the relevant GPIO pins as output
  BLINK_GPIO->PDDR |= (1 << BLINK_PIN);
  // Drive all low (set bits which are selected by the given mask)
  BLINK_GPIO->PCOR = (1 << BLINK_PIN);

  // Select GPIO function in the pinmuxes for all LED pins
  PORTD->PCR[BLINK_PIN] = PORT_PCR_MUX(1);

#endif // IS_SDA_MCU

  while (1) { 
    for (uint32_t u = 0; u < 1000000; u++) {
      // dummy read to spend time and not let compiler optimize this away
      (void)BLINK_GPIO->PDIR;
    }

    // Flip a single output bit (just a write)
    BLINK_GPIO->PTOR = (1 << BLINK_PIN);
  }

  // never reached
}
