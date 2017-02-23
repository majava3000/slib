#pragma once

/**
 * The exception vectors are core type specific (mostly shared), and injected
 * by the ARM SVD tools normally. However, since we don't have support for that
 * yet, just describe the generic IRQns here (SysTick_IRQn is required by CMSIS,
 * and IRQn_Type is quite primitive).
 *
 * Later the register emitting tool will have to learn this and these should be
 * split across core types and chip-family specific stuff (latter is described
 * in SVD, and for some chips there might be SVD entries that stop emitting some
 * core IRQn, like SysTick_IRQn with some nRFs).
 *
 * The negative numbering comes from the way that the CMSIS NVIC functions
 * handle updating different register sets depending on whether the IRQn is for
 * internal core use or whether it's vendor integration provided. A single
 * unsigned space would've been nicer, but we don't want to replicate core CMSIS
 * functionality at this point, so let's be compatible.
 */
typedef enum IRQn {
  NonMaskableInt_IRQn   = -14,
  HardFault_IRQn        = -13,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn         = -11,
  UsageFault_IRQn       = -10,
  SVCall_IRQn           = -5,
  DebugMonitor_IRQn     = -4,
  PendSV_IRQn           = -2,
  SysTick_IRQn          = -1,
} IRQn_Type;
