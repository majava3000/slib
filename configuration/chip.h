/**
 * TODO: This file should be generated and drives the cmsis integration
 *       and perhaps other features as well
 */
#pragma once

// Compiler will set automatically the ARCH separately which can be used to
// select which versions of functions to generate

#define CHIP_CORE_CORTEX_CM4 (1)

// for K64 (note that vendor files get this wrong, which is "funny")
#define CHIP_HAS_FPU (1)
#define CHIP_HAS_MPU (1)
#define CHIP_NVIC_BITS (4)

// TODO:
// How to expose bitbanding?