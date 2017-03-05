#pragma once

/**
 * Map design names into physical names
 * All configurable pins are named and referred in the schema, although not
 * perhaps used in the final design
 *
 * NOTE: Negative logic pin names prefixed with 'n' instead of _B suffix
 */

#include "configuration/pins_k20_50.h"

// These pins are used to program K20_50
#define PIN_SDA_JTAG_TCLK     PIN_PTA0
#define PIN_SDA_JTAG_TDI      PIN_PTA1
#define PIN_SDA_JTAG_TDO      PIN_PTA2
#define PIN_SDA_JTAG_TMS      PIN_PTA3

// Turns into SDA_SWD_EN via U9 buffer
#define PIN_nSDA_SWD_EN       PIN_PTA4

// 8MHz crystal for K20 (unused)
#define PIN_EXTAL             PIN_PTA18
#define PIN_XTAL              PIN_PTA19

// Turns into SDA_SWD_OE via U9 buffer
#define PIN_nSDA_SWD_OE       PIN_PTB0
#define PIN_nSDA_RST_TGTMCU   PIN_PTB1

// Unclear, disable for now
#define PIN_nSDA_SPI0_RST     PIN_PTC1
#define PIN_SDA_SPI0_CS       PIN_PTC2

// UART from main MCU. Note that direction indicated in names from main MCU's
// side
#define PIN_nUART1_TX_TGTMCU  PIN_PTC3
#define PIN_nUART1_RX_TGTMCU  PIN_PTC4

// Names here from SDA MCU's side. SCK -> SWD_CLK, SIN+SOUT -> SWD_SIO (bidir)
#define SDA_SPI0_SCK          PIN_PTC5
#define SDA_SPI0_SOUT         PIN_PTC6
#define SDA_SPI0_SIN          PIN_PTC7

// Sinks current going through D2 (Green led)
#define PIN_SDA_LED           PIN_PTD4
// Can be used to measure the voltage via a divider (ADC possible)
#define PIN_SDA_USB_P5V_SENSE PIN_PTD5
// Can be used to enable the MC2005 regulator to supply additional power
#define PIN_POWER_EN          PIN_PTD6 
// Feedback from MC2005 to indicate fault (overcurrent or other situation)
#define PIN_nVTRG_FAULT       PIN_PTD7
