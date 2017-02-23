/**
 * C-startup for Cortexes
 *
 * TODO: Update with difference for CM0 and CM0+ as well (also the new ones
 *       once have something to test against)
 */

#include <stdint.h>
#include "cmsis.h" // NVIC_SystemReset test code uses this only now

// Symbols defined by the linker:
extern uint32_t __text_end;   // where init data is on flash
extern uint32_t __data_start; // where it should be copied to
extern uint32_t __data_end;   // where it ends after copying (to calc count)
extern uint32_t __bss_start;  // start of bss (zeroing starts here)
extern uint32_t __bss_end;    // bss end (to calc count)
extern uint32_t __stack_top;  // SP after reset

typedef void (*VectorEntry)(void);

#define DECLARE_HANDLER(name) \
  void name##_Handler(void) __attribute__((weak, alias("Unhandled_Handler")))

DECLARE_HANDLER(NMI);
DECLARE_HANDLER(HardFault);
DECLARE_HANDLER(MemManage);
DECLARE_HANDLER(BusFault);
DECLARE_HANDLER(UsageFault);
DECLARE_HANDLER(SVC);
DECLARE_HANDLER(DebugMon);
DECLARE_HANDLER(PendSV);
DECLARE_HANDLER(SysTick);

// These two are also defined in this same file, so we can't use the same
// declaration as above, since this will lead to dual declarations
void Reset_Handler(void) __attribute__((weak,noreturn,naked));
void Unhandled_Handler(void) __attribute__((weak,noreturn));

// Called the very first thing
extern void init0(void) __attribute__((weak));

// This must be defined somewhere else
extern int main(void);

// Support placing special magic data into the interrupt table into the reserved
// slots
#ifndef CRT0_EXCEPTION7_DATA
  #define CRT0_EXCEPTION7_DATA (0)
#endif
#ifndef CRT0_EXCEPTION8_DATA
  #define CRT0_EXCEPTION8_DATA (0)
#endif
#ifndef CRT0_EXCEPTION9_DATA
  #define CRT0_EXCEPTION9_DATA (0)
#endif
#ifndef CRT0_EXCEPTION10_DATA
  #define CRT0_EXCEPTION10_DATA (0)
#endif
#ifndef CRT0_EXCEPTION13_DATA
  #define CRT0_EXCEPTION13_DATA (0)
#endif

// TODO:
//  How to deal with target specific vector contents? We'll want to setup all
//  the pointers ready to be used, but this depends on the chip data
//  Perhaps we could use the vectors section to do back-to-back merging?
const static VectorEntry cCoreVectors[] __attribute__((section("vectors"),used)) = {
  (VectorEntry)&__stack_top,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  (VectorEntry)CRT0_EXCEPTION7_DATA,
  (VectorEntry)CRT0_EXCEPTION8_DATA,
  (VectorEntry)CRT0_EXCEPTION9_DATA,
  (VectorEntry)CRT0_EXCEPTION10_DATA,
  SVC_Handler,
  DebugMon_Handler,
  (VectorEntry)CRT0_EXCEPTION13_DATA,             
  PendSV_Handler,
  SysTick_Handler,
};

// By default, do nothing. However, linker doesn't seem to be able to throw this
// away anyway, even if the strong symbol overrides this one. Sigh.
void init0(void) {};

void Reset_Handler(void) {
  // do any target specific very early setup. must not use bss/rwdata
  init0();

  // Place breakpoint here if you want to start as early as possible (some
  // SoC might have specific timing requirements for init0 code that must
  // execute within specific number of clocks after reset, and if that timing
  // is delayed, something bad will happen. Kinetis).

  // TODO: Check whether using indices below will result in slightly better code
  
  // init bss
  uint32_t* dest = &__bss_start;
  while (dest < &__bss_end) {
    *dest = 0;
    dest ++;
  }
  // copy rw-data
  dest = &__data_start;
  const uint32_t* src = &__text_end;
  while (dest < &__data_end) {
    *dest = *src;
    dest ++;
    src ++;
  }

  (void)main();
  NVIC_SystemReset();
  // this won't be reached
  // TODO: Find a way to satisfy noreturn without adding extra code
  while(1);
}

/* Default infinite-loop vector
   NOTE: Using __attribute__((interrupt)) causes gcc to issue an extra prolog
         similar to what is used with 32-bit ARM. However, on cortex this isn't
         a good idea, so never mark functions as interrupts for gcc with cortex
*/
void Unhandled_Handler(void) {
  while (1);
}
