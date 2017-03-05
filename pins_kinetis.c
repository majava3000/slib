#include "configuration/pins_kinetis.h"

// The ports and gpios are identically integrated on all. Just don't touch the
// ones that might not be present
#include "registermap/arm/kinetis/mk65f18/regmap/port.h"
#include "registermap/arm/kinetis/mk65f18/regmap/gpio.h"

#define INSTANCE_COUNT (sizeof(gKinetisPORT)/sizeof(gKinetisPORT[0]))

// Get the instance from pin
#define PIN_GET_INSTANCE(p) ((p) >> 5)
// Get the pin index from pin
#define PIN_GET_INDEX(p) ((p) & 31)

// Helper to indicate whether pinmux requires GPIO control or not
#define IS_PINMUX_GPIO(pinmux) (((pinmux) & 0b111) == 1)


#define PORT_PCR_MUX(n) \
  ((((n) << PORT_PCR_MUX_offset) & PORT_PCR_MUX_mask))

void Pin_configure(Pin pin, uint8_t pinmux, uint8_t flags) {

  // isolate the instance
  unsigned instance = PIN_GET_INSTANCE(pin);

  // don't do anything if invalid (avoid harmful side-effects)
  // TODO: Prefer build-time asserts here and controlled failure processing for
  //       cases which are not static
  if (instance >= INSTANCE_COUNT) {
    return;
  }

  // NOTE: When disabling/setting to analog a pin, the pullup/pulldowns are not
  //       valid flag choices. Neither are they valid choices when setting up
  //       for output. They're valid for alt settings where peripherals run the
  //       pins as inputs though (ie, pullup/down also works outside GPIO in
  //       some cases).

  unsigned index = PIN_GET_INDEX(pin);

  // overall update strategy for Kinetis:
  // if the new pinmux setting is a GPIO one, we need to setup the GPIO first
  // and after that the PCR that might enable the GPIO to be seen externally.
  // TODO: review this strategy, there are probably cases where we'd like to
  //       see the pullup/pulldown to be activated before switching to input
  //       for example.

  // NOTE: if pinmux has already selected GPIO as the peripheral that controls
  //       the pin, then the below GPIO setup will be seen as it happens
  //       externally. If this is problematic, disable the pin first

  // If the new setting is GPIO, we need to setup the GPIO stuff first (pinmux
  // will always switch last)
  if (IS_PINMUX_GPIO(pinmux)) {
    // GPIO registers are manipulated with pinmasks, so prepare one here
    uint32_t pinMask = 1U << index;
    if (pinmux == PINMUX_INPUT) {
      // just set the GPIO direction to input and be done with it. This is done
      // by clearing the respective bit in PDDR
      gKinetisGPIO[instance]->PDDR &= ~pinMask;
    } else {
      // output will be required. Don't set direction until we've set the proper
      // output level
      if (pinmux == PINMUX_OUTPUT_LOW) {
        // drive to low level by "clearing" PDOR bit at pin position
        gKinetisGPIO[instance]->PCOR = pinMask;
      } else {
        // drive to high by "setting" PDOR bit at pin position
        gKinetisGPIO[instance]->PSOR = pinMask;
      }

      // Switch direction to output
      gKinetisGPIO[instance]->PDDR |= pinMask;
    }
  }

  // make a version of the CPR in which we've cleared the bits that we won't
  // be writing (since they're w1c) or which we'll provide below. Default
  // values for the fields will then be zero (for the ones that we provide)
  uint32_t pcr = gKinetisPORT[instance]->PCR[index] &
                 ~(PORT_PCR_ISF_mask |
                   PORT_PCR_MUX_mask |
                   PORT_PCR_PE_mask  |
                   PORT_PCR_PS_mask);
  // Fill up the PCR settings based on pinmux and flags. the macro has an
  // internal mask anyway, so the non alt selection bits are dropped here
  pcr |= PORT_PCR_MUX(pinmux);

  if (flags & (PINMUX_FLAG_PULLUP | PINMUX_FLAG_PULLDOWN)) {
    // either a pullup or pulldown will be used (enable "pull")
    pcr |= PORT_PCR_PE_mask;
    // if both are used, pullup will win since it's non-zero in PCR
    if (flags & PINMUX_FLAG_PULLUP) {
      // enable pullup instead of pulldown
      pcr |= PORT_PCR_PS_mask;
    }
  } else {
    // pullup and pulldown will be disabled on this pin
  }

  // Update the PCR which concludes the setup
  gKinetisPORT[instance]->PCR[index] = pcr;
}

/**
 * NOTE: The code below is "ok" but far from most efficient on kinetis.
 *       More efficient approaches might be added later, but they do have their
 *       own drawbacks.
 */

// TODO: Add failure processing
void Pin_setOutput(Pin p, uint8_t level) {

  unsigned instance = PIN_GET_INSTANCE(p);
  unsigned index =    PIN_GET_INDEX(p);
  uint32_t pinMask = (1U << index);

  level &= 1;

  if (level) {
    gKinetisGPIO[instance]->PSOR = pinMask;
  } else {
    gKinetisGPIO[instance]->PCOR = pinMask;
  }
}

// TODO: Add failure processing
uint8_t Pin_getInput(Pin p) {

  unsigned instance = PIN_GET_INSTANCE(p);
  unsigned index =    PIN_GET_INDEX(p);

  return (gKinetisGPIO[instance]->PDIR >> index) & 1;
}

// TODO: Add failure processing
// For targets that don't support toggle directly, add a getOutput and do it
// manually
void Pin_toggleOutput(Pin p) {

  unsigned instance = PIN_GET_INSTANCE(p);
  unsigned index =    PIN_GET_INDEX(p);
  uint32_t pinMask = (1U << index);

  gKinetisGPIO[instance]->PTOR = pinMask;
}
