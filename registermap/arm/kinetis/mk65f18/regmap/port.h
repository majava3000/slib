#pragma once

#include "../../shared/port.h"

#define PORTA ((struct PORTRegisters*)0x40049000)
#define PORTB ((struct PORTRegisters*)0x4004A000)
#define PORTC ((struct PORTRegisters*)0x4004B000)
#define PORTD ((struct PORTRegisters*)0x4004C000)
#define PORTE ((struct PORTRegisters*)0x4004D000)

// TODO: This is a bit of a hack, since use will cause pulling of all of it into
//       section, even if only one would be used
static const typeof(PORTA) gKinetisPORT[] = {
  PORTA, PORTB, PORTC, PORTD, PORTE
};
