#include <stdint.h>

struct PKG_GPIORegisters {
  volatile uint32_t PDOR;       // Port Data Output Register [0]
  volatile uint32_t PSOR;       // Port Set Output Register [4]
  volatile uint32_t PCOR;       // Port Clear Output Register [8]
  volatile uint32_t PTOR;       // Port Toggle Output Register [c]
  volatile uint32_t PDIR;       // Port Data Input Register [10]
  volatile uint32_t PDDR;       // Port Data Direction Register [14]
};

#define PKG_GPIOA ((struct PKG_GPIORegisters*)0x400FF000)
#define PKG_GPIOB ((struct PKG_GPIORegisters*)0x400FF040)
#define PKG_GPIOC ((struct PKG_GPIORegisters*)0x400FF080)
#define PKG_GPIOD ((struct PKG_GPIORegisters*)0x400FF0C0)
#define PKG_GPIOE ((struct PKG_GPIORegisters*)0x400FF100)

// // TODO: This is a bit of a hack, since use will cause pulling of all of it into
// //       section, even if only one would be used
// static const typeof(GPIOA) gKinetisGPIO[] = {
//   GPIOA, GPIOB, GPIOC, GPIOD, GPIOE
// };

#define PKG_TOGGLE_PIN(gpio, pinNum) \
do { \
  (gpio)->PTOR = (1U << (pinNum)); \
} while (0)
