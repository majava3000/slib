#pragma once

#include "../../shared/uart.h"

// UART0 has also smart-card specific registers, but they do not overlap (not
// supported now).
// We use the same regmap as with 26/65/66, although 20 is missing some features
// - BDH.SBNS, C5.{TCDMAS,ILDMAS,LBKDDMAS}, CFIFO.RXOFE, SFIFO.RXOFE

#define UART0 ((struct UARTRegisters*)0x4006A000)
#define UART1 ((struct UARTRegisters*)0x4006B000)
#define UART2 ((struct UARTRegisters*)0x4006C000)

// TODO: This is a bit of a hack, since use will cause pulling of all of it into
//       section, even if only one would be used
static const typeof(UART0) gKinetisUART[] = {
  UART0, UART1, UART2
};
