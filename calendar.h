#pragma once
/**
 * Modern Gregorian calendar based breakdown and combination support to replace
 * C stdlib functions gmtime, localtime, mktime
 *
 * Copyright 2017 Aleksandr Koltsoff (czr@iki.fi)
 *
 * (please see source file for full license text)
 *
 * SPDX-License-Identifier: MIT
 *
 * Features:
 * - Always re-entrant capable functions (all functions are pure and const'able)
 * - Portable (C99)
 * - Structures and ranges scaled to be suitable for resource constrained
 *   environments
 * - All broken down fields are zero based
 *   - Year field is an offset against minimum allowed year, so might not be
 *     "zero based" depending on interpretation.
 * - Additional granularity available for partial conversions (when only time
 *   or date is of interest)
 * - Separate function to determine day of the week directly from unixtime
 *
 * Limitations:
 * - No leap second support (assumes de facto standard "unix time" convention)
 * - No timezone support (implied or explicit) (no surprises either)
 * - No "normalization" of dates in combine (unlike some mktime implementations)
 * - No checks for invalid dates upon combination
 * - No support for dates older than 1970 (see below on types)
 *
 * Types:
 * - Linear time is represented by uint32_t, using "unix time" convention where
 *   the number represents seconds since "the UNIX epoch", without including
 *   any leapseconds. Unlike time_t, the uint32_t is enough to represent time
 *   up to the year 2106.
 *   - NOTE: While technically modern time implementations can be made to
 *           support handling of leap seconds (glibc at least), most systems do
 *           not enable this functionality. Having leap second support becomes
 *           an interesting problem once you start communicating timestamps to
 *           systems that do not have leap second support. Leap second support
 *           might be implemented as an option later (as well as a simple
 *           tz+dst implementation on top of this implementation, and
 *           conversions to/from TAI)
 */

#include <stdint.h>

/**
 * Broken down date representation
 */
typedef struct CalendarDate {
  uint8_t year;  // (1970 +) 0-255
  uint8_t month; // 0-11
  uint8_t day;   // 0-31
} CalendarDate;

/**
 * Broken down time represetation
 */
typedef struct CalendarTime {
  uint8_t hour;   // 0-23
  uint8_t minute; // 0-59
  uint8_t second; // 0-59 (no leap second support)
} CalendarTime;

/**
 * Combination of broken down date and time
 * Since all internal fields are bytes, the compiler should be able to align
 * this at any alignment and this should not require any internal nor external
 * padding.
 */
typedef struct Calendar {
  CalendarDate date;
  CalendarTime time;
} Calendar;

/**
 * Store broken down calendar representation of given unixtime
 */
void Calendar_breakdown(uint32_t secondsSinceEpoch, Calendar* output);

/**
 * Store broken down time representation of given "number of seconds since
 * day start"
 */
void Calendar_breakdownTime(uint32_t secondsSinceMidnight, CalendarTime* output);

/**
 * Store broken down date representation of given "days since unix epoch"
 */
void Calendar_breakdownDate(uint32_t daysSinceEpoch, CalendarDate* output);

/**
 * Given broken down calendar representation, return unixtime.
 *
 * To get seconds since midnight, leave the date as zero in the input.
 * To get days since epoch, leave the time as zero in the input and divide
 * result by 86400 (seconds per day in unixtime).
 *
 * There is no check against invalid pointers, nor invalid structure fields.
 */
uint32_t Calendar_combine(const Calendar* input);

/**
 * Returns the number of day of the week given unixtime
 *
 * 0: Monday .. 6: Sunday
 */
uint8_t Calendar_getDayOfWeek(uint32_t secondsSinceEpoch);

// Convenience defines for users of Calendar_getDayOfWeek

#define CALENDAR_MONDAY    (0)
#define CALENDAR_TUESDAY   (1)
#define CALENDAR_WEDNESDAY (2)
#define CALENDAR_THURSDAY  (3)
#define CALENDAR_FRIDAY    (4)
#define CALENDAR_SATURDAY  (5)
#define CALENDAR_SUNDAY    (6)

// Convenience define if dealing with partial forming. The name is slightly
// misleading, since it does not convey lack of leap second support.
#define CALENDAR_SECONDS_PER_DAY (86400)
