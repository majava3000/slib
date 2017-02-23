// Use the wdog setup from specific MCU type that is the source
// for other Kinetis Ks for now.
// TODO: Need a bettery way for this
#include "registermap/arm/kinetis/mk65f18/regmap/wdog.h"

// This is reserved (1) in the datasheet, but was called STNDBYEN by existing
// code ( https://github.com/laswick/kinetis/blob/master/phase2_embedded_c/watchDog.c )
#define WDOG_STCTRLH_STNDBYEN_mask (0x100U)

/**
 * First thing that must be done in a Kinetis at startup, is disabling the
 * watchdog. This is called from ResetHandler immediately at startup, so nothing
 * extra should be done here. Ever.
 */
void init0(void) {
  // Disable watchdog first. Must happen within 20 bus cycles
  WDOG->UNLOCK = WDOG_UNLOCK_KEY1;
  WDOG->UNLOCK = WDOG_UNLOCK_KEY2;
  // Set the reserved(1), enable WDOG in CPU WAIT and STOP (but not DEBUG),
  // Allow writing to watchdog write-once registers, select alternate clock
  // source (not LPO, so bus clock) for clock source. KSDKv1 does this, so
  // we as well.
  WDOG->STCTRLH = WDOG_STCTRLH_STNDBYEN_mask |
                  WDOG_STCTRLH_WAITEN_mask |
                  WDOG_STCTRLH_STOPEN_mask |
                  WDOG_STCTRLH_ALLOWUPDATE_mask |
                  WDOG_STCTRLH_CLKSRC_mask;
}
