#pragma once
/**
 * User configuration for util/calendar
 */

/**
 * Optional integration hook to return current unixtime of system. Must be
 * defined as a symbol that can be linked against using the following
 * prototype:
 *
 *   uint32_t CALENDAR_GET_NOW(void)
 *
 * When defined, additional functions become available (ending with Now) that
 * will return results based on curren time instead of the given unixtime.
 *
 * This is mainly useful, if you find your code littered with the following
 * pattern:
 *
 *   uint32_t now = GetYourGetUnixTimeU32();
 *   Calendar decomposed;
 *   Calendar_decompose(now, &decomposed);
 *
 * When the define is set, the code be re-written as follows:
 *
 *   Calendar decomposedNow;
 *   Calendar_decomposeNow(&decomposed);
 *
 * YMMV whether hiding this convenience in the code will result in global code
 * size reduction or expansion.
 */
#define CALENDAR_GET_NOW System_getUnixtime
