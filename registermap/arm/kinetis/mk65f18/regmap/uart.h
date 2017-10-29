#pragma once

#include "../../shared/uart.h"

// UART0 has also smart-card specific registers, but they do not overlap (not
// supported now)

#define UART0 ((struct UARTRegisters*)0x4006A000)
#define UART1 ((struct UARTRegisters*)0x4006B000)
#define UART2 ((struct UARTRegisters*)0x4006C000)
#define UART3 ((struct UARTRegisters*)0x4006D000)
#define UART4 ((struct UARTRegisters*)0x400EA000) // NOTE discontinuity

// TODO: This is a bit of a hack, since use will cause pulling of all of it into
//       section, even if only one would be used
static const typeof(UART0) gKinetisUART[] = {
  UART0, UART1, UART2, UART3, UART4
};
