#pragma once

#include "../../shared/port.h"

#define PORTA ((PORTRegisters*)0x40049000)
#define PORTB ((PORTRegisters*)0x4004A000)
#define PORTC ((PORTRegisters*)0x4004B000)
#define PORTD ((PORTRegisters*)0x4004C000)
#define PORTE ((PORTRegisters*)0x4004D000)

// TODO: This is a bit of a hack, since use will cause pulling of all of it into
//       section, even if only one would be used
static const typeof(PORTA) gKinetisPORT[] = {
  PORTA, PORTB, PORTC, PORTD, PORTE
};