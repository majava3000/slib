#pragma once
/**
 * Modern Gregorian calendar based breakdown and combination support to replace
 * C stdlib functions gmtime, localtime, mktime and to help decompose/compose
 * broken down representations used in GNSS and calendar-style RTC devices.
 *
 * Copyright 2017 Aleksandr Koltsoff (czr@iki.fi).
 *
 * (please see source file for full license text)
 *
 * SPDX-License-Identifier: MIT
 *
 * Canonical "project" URL: https://github.com/majava3000/slib/tree/master/util
 *
 * Features:
 * - Always re-entrant capable functions (all functions are pure and const'able)
 * - Portable. No dependencies on C library other than stdint.h (and C99)
 * - Structures and ranges scaled to be suitable for resource constrained
 *   environments
 * - All broken down fields are zero based
 *   - Year field is an offset against minimum allowed year, so might not be
 *     "zero based" depending on interpretation. Epoch compatible with unixtime
 *     epoch is used to simplify use.
 * - Additional granularity available for partial conversions (when only time
 *   or date is of interest)
 * - Separate function to determine day of the week directly from unixtime
 * - All calculations are done in unsigned space (making analysis easier)
 *
 * Limitations:
 * - No leap second support (assumes de facto standard "unix time" convention)
 * - No timezone support (implied or explicit) (no surprises either)
 * - No "normalization" of dates in combine (unlike some mktime implementations)
 * - No checks for invalid dates upon combination (an validator might be added
 *   later)
 * - No support for dates older than 1970 (see below on types)
 * - Maximum valid year is 2099. It is reduced by 2 (to 2104) due to
 *   simplification for leap year calculation (1970 is not a leap year) and
 *   further reduced to 2099 due to missing centennial leap year correction
 *   (which is otherwise not required, due to year 2000 cancelling out the
 *   centennial leap year). This means that values above 4102444799 are
 *   available as canary values or for other use, as long as they're never used
 *   with the Calendar_combine nor Calendar_combineDate.
 * - No API to retrieve day of year (tm_yday). However, most cases using that
 *   field are using it to shortcut comparison across month/day fields, which
 *   are easy and light-weight to compare with the small structures here.
 *
 * Types:
 * - Linear time is represented by uint32_t, using "unix time" convention where
 *   the number represents seconds since "the UNIX epoch", without including
 *   any leapseconds. Unlike time_t, the uint32_t is enough to represent time
 *   up to the year 2106 (minus the caveat above for combining).
 *
 * Tests:
 * - Each release undergoes "brute force" testing all day change points (with
 *   also testpoint-1 and testpoint+1 tests) as well as randomized run and all
 *   valid range ends. Tests compare results against a system provided gmtime
 *   (on a relatively modern Linux). Tests are not included in distribution.
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
// UNIMPLEMENTED
// uint32_t Calendar_combine(const Calendar* input);

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
