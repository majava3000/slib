#pragma once

/**
 * Map design names into physical names
 *
 * NOTE: Negative logic pin names prefixed with 'n' instead of _B suffix
 */

#include "configuration/pins_k64_120_lqfp144.h"

// Most of the pins are not listed here for now (will be added as we go if/when
// required)

// RGB LED
#define PIN_LED_RED   PIN_PTB22
#define PIN_LED_GREEN PIN_PTE26
#define PIN_LED_BLUE  PIN_PTB21

// SW3 is connected to NMI and LLWU capable pin. ext pull-up DNPed
#define PIN_nSW3      PIN_PTA4
// SW2 is connected to PDB0_EXTRG and LLWU capable pin. ext pull-up DNPed
#define PIN_nSW2      PIN_PTC6
