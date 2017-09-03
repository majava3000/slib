#pragma once

#include "../../shared/gpio.h"

#define GPIOA ((struct GPIORegisters*)0x400FF000)
#define GPIOB ((struct GPIORegisters*)0x400FF040)
#define GPIOC ((struct GPIORegisters*)0x400FF080)
#define GPIOD ((struct GPIORegisters*)0x400FF0C0)
#define GPIOE ((struct GPIORegisters*)0x400FF100)

// TODO: This is a bit of a hack, since use will cause pulling of all of it into
//       section, even if only one would be used
static const typeof(GPIOA) gKinetisGPIO[] = {
  GPIOA, GPIOB, GPIOC, GPIOD, GPIOE
};