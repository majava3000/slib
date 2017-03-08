#pragma once

/**
 * Pins are arranged encoded in a linear list so that pins on port A map into
 * pins 0-31, etc. Keeping them linear allows smallest datatype to be used, but
 * is restricted to local GPIO pins only (ie, not useful to represent pins
 * behind an I2C I/O extender for example, which would require a higher level
 * and more abstract interface anyway).
 */

#include <stdint.h>

// A simple linearly identifyable pin. enough for 8 ports, and kinetis only has
// max 5 (so over half populated).
typedef uint8_t Pin;

// Create a pin from instance and pin identifier
#define MAKE_PIN(instance, pinIndex) \
  (Pin)( ((instance) << 5) | pinIndex )

// Disable connection to digital circuits (analog connection might exist)
#define PINMUX_DISABLED (0)
#define PINMUX_ANALOG   PINMUX_DISABLED

// Note that there is no specific mechanism to select just ALT1 (GPIO). Instead,
// one must use one of the three extended PINMUX selectors (INPUT, OUTPUT_LOW
// and OUTPUT_HIGH below)

// Alt settings 2..7 select non-GPIO peripherals (if any)
#define PINMUX_ALT2     (2)
#define PINMUX_ALT3     (3)
#define PINMUX_ALT4     (4)
#define PINMUX_ALT5     (5)
#define PINMUX_ALT6     (6)
#define PINMUX_ALT7     (7)

// Pseudo pinmux modes that all select the GPIO ALT1 but additionally cause
// controlling of the GPIO block. These all alias to ALT1 setting if all but the
// lowest 3 bits are masked.
#define PINMUX_INPUT       ((0 << 3)+1)
#define PINMUX_OUTPUT_LOW  ((1 << 3)+1)
#define PINMUX_OUTPUT_HIGH ((2 << 3)+1)

// Pin flags, modifying the operation somehow
#define PINMUX_FLAG_NONE     (0)

// Flag to request pull-up
// NOTE: Other flags will be added later, or re-designed perhaps
#define PINMUX_FLAG_PULLUP   (1 << 0)
#define PINMUX_FLAG_PULLDOWN (1 << 1)

/**
 * Setup pin for operation
 * TODO: open drain, drive strength, skew etc not yet supported
 */
void Pin_configure(Pin p, uint8_t pinmux, uint8_t flags);

/**
 * Drive pin to given level. 0 = low, 1 = high if pin set up for output
 */
void Pin_setOutput(Pin p, uint8_t level);

/**
 * Get pin level if pin configured as input.
 * 0 = low level, 1 = high level
 */
uint8_t Pin_getInput(Pin p);

/**
 * Toggle pin output (low to high and high to low) if pin set up for output.
 */
void Pin_toggleOutput(Pin p);
