#pragma once
/**
 * Register definitions for WDOG peripheral
 * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY
 */

#include <stdint.h>

struct WDOGRegisters {
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
};

// STCTRLH (Watchdog Status and Control Register High)
#define STCTRLH_WDOGEN             (0x0001U) // Enables or disables the WDOG's operation
#define STCTRLH_WDOGEN_offset      (0)
#define STCTRLH_CLKSRC             (0x0002U) // Selects clock source for the WDOG timer and other internal timing operations
#define STCTRLH_CLKSRC_offset      (1)
#define STCTRLH_IRQRSTEN           (0x0004U) // Used to enable the debug breadcrumbs feature
#define STCTRLH_IRQRSTEN_offset    (2)
#define STCTRLH_WINEN              (0x0008U) // Enables Windowing mode
#define STCTRLH_WINEN_offset       (3)
#define STCTRLH_ALLOWUPDATE        (0x0010U) // Enables updates to watchdog write-once registers, after the reset-triggered initial configuration window (WCT) closes, through unlock sequence
#define STCTRLH_ALLOWUPDATE_offset (4)
#define STCTRLH_DBGEN              (0x0020U) // Enables or disables WDOG in Debug mode
#define STCTRLH_DBGEN_offset       (5)
#define STCTRLH_STOPEN             (0x0040U) // Enables or disables WDOG in Stop mode
#define STCTRLH_STOPEN_offset      (6)
#define STCTRLH_WAITEN             (0x0080U) // Enables or disables WDOG in Wait mode
#define STCTRLH_WAITEN_offset      (7)
#define STCTRLH_TESTWDOG           (0x0400U) // Puts the watchdog in the functional test mode
#define STCTRLH_TESTWDOG_offset    (10)
#define STCTRLH_TESTSEL            (0x0800U) // Effective only if TESTWDOG is set. Selects the test to be run on the watchdog timer
#define STCTRLH_TESTSEL_offset     (11)
#define STCTRLH_BYTESEL_mask       (0x3000U) // This 2-bit field selects the byte to be tested when the watchdog is in the byte test mode
#define STCTRLH_BYTESEL_width      (2)
#define STCTRLH_BYTESEL(n)         ((n) << STCTRLH_BYTESEL_offset)
#define STCTRLH_BYTESEL_get(n)     (((n) >> STCTRLH_BYTESEL_offset) & 0x3U)
#define STCTRLH_BYTESEL_offset     (12)
#define STCTRLH_DISTESTWDOG        (0x4000U) // Allows the WDOG's functional test mode to be disabled permanently
#define STCTRLH_DISTESTWDOG_offset (14)

// STCTRLL (Watchdog Status and Control Register Low)
#define STCTRLL_INTFLG        (0x8000U) // Interrupt flag
#define STCTRLL_INTFLG_offset (15)

// PRESC (Watchdog Prescaler register)
#define PRESC_PRESCVAL_mask   (0x0700U) // 3-bit prescaler for the watchdog clock source
#define PRESC_PRESCVAL_width  (3)
#define PRESC_PRESCVAL(n)     ((n) << PRESC_PRESCVAL_offset)
#define PRESC_PRESCVAL_get(n) (((n) >> PRESC_PRESCVAL_offset) & 0x7U)
#define PRESC_PRESCVAL_offset (8)
