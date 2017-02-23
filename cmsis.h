/**
 * Pulls in the CMSIS core functionality with the chip-specific configuration
 * set. Pull this file to get the correct CMSIS implementation in.
 */
#pragma once

#include "configuration/chip.h"
// Forward the chip specific settings to CMSIS compatible ones
#define __FPU_PRESENT (CHIP_HAS_FPU)
#define __MPU_PRESENT (CHIP_HAS_MPU)
#define __NVIC_PRIO_BITS (CHIP_NVIC_BITS)

// HACK to get the IRQn_Type in (not yet chip-specific)
#include "irqn.h"

#if defined(CHIP_CORE_CORTEX_CM0)
  #include "vendor/CMSIS/CMSIS/core_cm0.h"
#elif defined(CHIP_CORE_CORTEX_CM0P)
  #include "vendor/CMSIS/CMSIS/core_cm0plus.h"
#elif defined(CHIP_CORE_CORTEX_CM3)
  #include "vendor/CMSIS/CMSIS/core_cm3.h"
#elif defined(CHIP_CORE_CORTEX_CM4)
  #include "vendor/CMSIS/CMSIS/core_cm4.h"
#else
  #warning "Don't know which CMSIS header to include"
#endif
