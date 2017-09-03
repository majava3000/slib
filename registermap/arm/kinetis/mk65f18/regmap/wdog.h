#pragma once

#include "../../shared/wdog.h"

#define WDOG ((struct WDOGRegisters*)0x40052000)

// WDOG registers are all back-to-back 16-bit
#define WDOG_UNLOCK_KEY1  0xC520
#define WDOG_UNLOCK_KEY2  0xD928
#define WDOG_REFRESH_KEY1 0xA602
#define WDOG_REFRESH_KEY2 0xB480
