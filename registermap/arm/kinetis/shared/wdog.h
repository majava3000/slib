#pragma once
/**
 * Register definitions for WDOG peripheral
 * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY
 */

#include <stdint.h>

typedef struct {
  volatile uint16_t STCTRLH;	// Watchdog Status and Control Register High [0]
  volatile uint16_t STCTRLL;	// Watchdog Status and Control Register Low [2]
  volatile uint16_t TOVALH;	// Watchdog Time-out Value Register High [4]
  volatile uint16_t TOVALL;	// Watchdog Time-out Value Register Low [6]
  volatile uint16_t WINH;	// Watchdog Window Register High [8]
  volatile uint16_t WINL;	// Watchdog Window Register Low [a]
  volatile uint16_t REFRESH;	// Watchdog Refresh register [c]
  volatile uint16_t UNLOCK;	// Watchdog Unlock register [e]
  volatile uint16_t TMROUTH;	// Watchdog Timer Output Register High [10]
  volatile uint16_t TMROUTL;	// Watchdog Timer Output Register Low [12]
  volatile uint16_t RSTCNT;	// Watchdog Reset Count register [14]
  volatile uint16_t PRESC;	// Watchdog Prescaler register [16]
} WDOGRegisters;

// STCTRLH (Watchdog Status and Control Register High)
#define WDOG_STCTRLH_WDOGEN_mask        (0x0001U) // Enables or disables the WDOG's operation
#define WDOG_STCTRLH_WDOGEN_offset      (0)
#define WDOG_STCTRLH_WDOGEN_width       (1)
#define WDOG_STCTRLH_CLKSRC_mask        (0x0002U) // Selects clock source for the WDOG timer and other internal timing operations
#define WDOG_STCTRLH_CLKSRC_offset      (1)
#define WDOG_STCTRLH_CLKSRC_width       (1)
#define WDOG_STCTRLH_IRQRSTEN_mask      (0x0004U) // Used to enable the debug breadcrumbs feature
#define WDOG_STCTRLH_IRQRSTEN_offset    (2)
#define WDOG_STCTRLH_IRQRSTEN_width     (1)
#define WDOG_STCTRLH_WINEN_mask         (0x0008U) // Enables Windowing mode
#define WDOG_STCTRLH_WINEN_offset       (3)
#define WDOG_STCTRLH_WINEN_width        (1)
#define WDOG_STCTRLH_ALLOWUPDATE_mask   (0x0010U) // Enables updates to watchdog write-once registers, after the reset-triggered initial configuration window (WCT) closes, through unlock sequence
#define WDOG_STCTRLH_ALLOWUPDATE_offset (4)
#define WDOG_STCTRLH_ALLOWUPDATE_width  (1)
#define WDOG_STCTRLH_DBGEN_mask         (0x0020U) // Enables or disables WDOG in Debug mode
#define WDOG_STCTRLH_DBGEN_offset       (5)
#define WDOG_STCTRLH_DBGEN_width        (1)
#define WDOG_STCTRLH_STOPEN_mask        (0x0040U) // Enables or disables WDOG in Stop mode
#define WDOG_STCTRLH_STOPEN_offset      (6)
#define WDOG_STCTRLH_STOPEN_width       (1)
#define WDOG_STCTRLH_WAITEN_mask        (0x0080U) // Enables or disables WDOG in Wait mode
#define WDOG_STCTRLH_WAITEN_offset      (7)
#define WDOG_STCTRLH_WAITEN_width       (1)
#define WDOG_STCTRLH_TESTWDOG_mask      (0x0400U) // Puts the watchdog in the functional test mode
#define WDOG_STCTRLH_TESTWDOG_offset    (10)
#define WDOG_STCTRLH_TESTWDOG_width     (1)
#define WDOG_STCTRLH_TESTSEL_mask       (0x0800U) // Effective only if TESTWDOG is set. Selects the test to be run on the watchdog timer
#define WDOG_STCTRLH_TESTSEL_offset     (11)
#define WDOG_STCTRLH_TESTSEL_width      (1)
#define WDOG_STCTRLH_BYTESEL_mask       (0x3000U) // This 2-bit field selects the byte to be tested when the watchdog is in the byte test mode
#define WDOG_STCTRLH_BYTESEL_offset     (12)
#define WDOG_STCTRLH_BYTESEL_width      (2)
#define WDOG_STCTRLH_DISTESTWDOG_mask   (0x4000U) // Allows the WDOG's functional test mode to be disabled permanently
#define WDOG_STCTRLH_DISTESTWDOG_offset (14)
#define WDOG_STCTRLH_DISTESTWDOG_width  (1)

// STCTRLL (Watchdog Status and Control Register Low)
#define WDOG_STCTRLL_INTFLG_mask   (0x8000U) // Interrupt flag
#define WDOG_STCTRLL_INTFLG_offset (15)
#define WDOG_STCTRLL_INTFLG_width  (1)

// PRESC (Watchdog Prescaler register)
#define WDOG_PRESC_PRESCVAL_mask   (0x0700U) // 3-bit prescaler for the watchdog clock source
#define WDOG_PRESC_PRESCVAL_offset (8)
#define WDOG_PRESC_PRESCVAL_width  (3)
