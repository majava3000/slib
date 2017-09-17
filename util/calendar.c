/**
 * Please see calendar.h for background and usage.
 *
 * Copyright 2017 Aleksandr Koltsoff (czr@iki.fi).
 *
 * Canonical "project" URL: https://github.com/majava3000/slib/tree/master/util
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * SPDX-License-Identifier: MIT
 */

#include "calendar.h"

#ifdef CALENDAR_GET_NOW
// Hopefully the user actually implements this interface, but no easy way of
// making sure unless closer coupling is forced.
uint32_t CALENDAR_GET_NOW(void);
#endif

// Depending on internal callpoint, we might want the current time in different
// representations. No-op if CALENDER_GET_NOW is not defined. This is slightly
// yucky but still relatively straight-forward.
#define _CALENDAR_FULL (0) // Return the unixtime as is
#define _CALENDAR_TIME (1) // Return seconds since midnight today
#define _CALENDAR_DATE (2) // Return days since epoch today

// Instead of littering all call points with the check, implement it here.
// If system time support is not required, this evaluates to transparent no-op
// and the compiler should optimize all call-points away.
static uint32_t optionalSystemTimeSupport(uint32_t v, uint8_t filter) {
#ifdef CALENDAR_GET_NOW
  if (v == CALENDAR_NOW) {
    v = CALENDAR_GET_NOW();
    // Since the different functions have different scales for the parameters,
    // depending on what is being called with CALENDAR_NOW, we need to do
    // additional pre-processing here. It's slightly yucky.
    if (filter == _CALENDAR_TIME) {
      return v % CALENDAR_SECONDS_PER_DAY;
    } else if (filter == _CALENDAR_DATE) {
      return v / CALENDAR_SECONDS_PER_DAY;
    }
    // leave the retrieved unixtime as is, will be returned below
  }
#endif
  return v;
}

void Calendar_decompose(uint32_t secondsSinceEpoch, Calendar* output) {

  secondsSinceEpoch = optionalSystemTimeSupport(secondsSinceEpoch,
                                                _CALENDAR_FULL);

  Calendar_decomposeDate(secondsSinceEpoch / CALENDAR_SECONDS_PER_DAY,
                         &output->date);
  Calendar_decomposeTime(secondsSinceEpoch % CALENDAR_SECONDS_PER_DAY,
                         &output->time);
}

void Calendar_decomposeTime(uint32_t secondsSinceMidnight, CalendarTime* output) {

  secondsSinceMidnight = optionalSystemTimeSupport(secondsSinceMidnight,
                                                   _CALENDAR_TIME);

  output->second = secondsSinceMidnight % 60;
  secondsSinceMidnight /= 60;
  output->minute = secondsSinceMidnight % 60;
  secondsSinceMidnight /= 60;
  output->hour = secondsSinceMidnight;
}

// Days per month (without including leap year extra day in February)
static const uint8_t sDaysPerMonth[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// Days in a common year (sum(sDaysPerMonth))
#define DAYS_PER_COMMON_YEAR (365)
// Days in a leap year
#define DAYS_PER_LEAP_YEAR (DAYS_PER_COMMON_YEAR + 1)
// Days in a four year cycle starting with a leap year
#define DAYS_PER_QUAD_CYCLE (DAYS_PER_LEAP_YEAR + DAYS_PER_COMMON_YEAR*3)

/**
 * Calculate the year offset, month offset and day offset against a start of
 * "quad". A quad is a time period that starts with the year that includes the
 * leap second, and continues for 4 years (ends just before the start of the
 * next year that contains a leap second).
 *
 * Within the quad, there is just one cutoff point (where the leap day is),
 * so we get away by a single comparison and post-adjustment if we hit exactly
 * the leap day)
 *
 * Once the leap day adjustment is done, we can have rest of the logic treat
 * each year as common (without leap days) simplifying the rest of the logic.
 *
 * The mechanism to pinpoint the month and day in month is currently linear
 * reduction which is O(n). This means that runtime will depend on the given
 * input which is not desireable. Perhaps this will be changed later if this
 * does not bloat generated constants/code too much.
 */
static void decomposeInQuad(uint32_t daysSinceQuadStart,
                                   CalendarDate* output) {

  // Will be set to one if we exactly hit the leap day within the quad. This
  // be added to the day index always at the end
  uint8_t leapDayOffset = 0;

  // Check whether we're in the post leap day section of the quad. If so, check
  // whether we're exactly at leap day as well (additional fixup needed)
  if (daysSinceQuadStart >= 31+28) {
    // At exactly leap day or after it

    if (daysSinceQuadStart == 31+28) {
      // exactly at leap day. mark for post-compensation
      leapDayOffset = 1;
    }
    // in all cases, we shift the view into the quad by one day so that we get
    // away by using non-leap-second days-per-month table
    daysSinceQuadStart -= 1;
  }

  // After this point we can assume each year is a common one.

  // Split into year and offset within year
  uint8_t yearInQuad = daysSinceQuadStart / DAYS_PER_COMMON_YEAR;
  // Initialized to the number of day within the year, but will be reduced
  // progressively to contain the number of day in month at the end
  uint16_t remDays = daysSinceQuadStart % DAYS_PER_COMMON_YEAR;

  // TODO: would be nice to find an O(1) for this. Now must use linear reduction
  //       which is O(n) and execution time will depend on parameters
  uint8_t monthIdx = 0;

  // locate the correct month while reducing the remainder of days (remainder
  // is the day of month)
  while (monthIdx < 11 &&
         remDays >= sDaysPerMonth[monthIdx]) {

    remDays -= sDaysPerMonth[monthIdx];
    monthIdx += 1;
  }

  // Output data, assuming that caller will do required fixup for the year based
  // on shift-compensation
  output->year = yearInQuad; // 0-3
  output->month = monthIdx; // 0-11
  output->day = remDays + leapDayOffset; // 0-30
}

void Calendar_decomposeDate(uint32_t daysSinceEpoch, CalendarDate* output) {
  // range of daysSinceEpoch: 0-47481 (2**32 / 86400 = 49710, however, since we
  // don't handle centennial cycles (nor quad-centennials), the maximum valid
  // day is the last one of year 2099). The absolute maximum is used as a
  // marker to retrieve current system time

  daysSinceEpoch = optionalSystemTimeSupport(daysSinceEpoch, _CALENDAR_DATE);

  // Our epoch (1970) isn't a leap year. We need to shift our view by exactly
  // two years to either side to get to the quad, so do that now before
  // isolating quad start and offset.
  uint32_t shiftedDaysSinceQuadEpoch = DAYS_PER_COMMON_YEAR +
                                       DAYS_PER_LEAP_YEAR +
                                       daysSinceEpoch;

  // isolate quad and offset within the quad
  uint32_t quadIndex = shiftedDaysSinceQuadEpoch / DAYS_PER_QUAD_CYCLE;
  uint32_t daysSinceQuadStart = shiftedDaysSinceQuadEpoch % DAYS_PER_QUAD_CYCLE;

  // run the quad part into storage
  decomposeInQuad(daysSinceQuadStart, output);

  // post-compensate the shift (2) and also adjust for the offset within the
  // origin space (4*quadIndex). This will never underflow. This is sligtly icky
  // since we now rewrite output, but from the caller's standpoint, it is infact
  // still only output (ie, we never read any data which user might have left in
  // 'output' before calling this function)
  output->year += quadIndex * 4 - 2;
}

uint8_t Calendar_getDayOfWeek(uint32_t secondsSinceEpoch) {
  // Unix epoch was a Thursday
  return (3 + (secondsSinceEpoch / CALENDAR_SECONDS_PER_DAY)) % 7;
}

uint32_t Calendar_compose(const Calendar* input) {
  // calculate number of full leap years between epoch and year but not
  // including the given year
  uint8_t leapCount = (input->date.year + 1) / 4;
  // number of non-leap years in the same period is everything rest
  uint8_t commonCount = input->date.year - leapCount;
  // number of days leading to the start of the given year
  uint32_t daysBeforeYear = leapCount * DAYS_PER_LEAP_YEAR +
                            commonCount * DAYS_PER_COMMON_YEAR;

  // this will contain 1 if we pass leap day within the given year
  uint32_t leapAdjustment = 0;
  if (input->date.year % 4 == 2) {
    // only adjust if we've crossed leap day
    if (input->date.month >= 2) {
      leapAdjustment = 1;
    }
  }

  // calculate number of days up to the month (monthIndex==0 => 0 days before)
  uint32_t daysBeforeMonth = 0;
  for (uint8_t u = 0; u < input->date.month; u++) {
    daysBeforeMonth += sDaysPerMonth[u];
  }

  uint32_t resultInDays = daysBeforeYear + daysBeforeMonth + leapAdjustment +
                          input->date.day;
  uint32_t secondOffset = 3600 * input->time.hour +
                          60 * input->time.minute +
                          input->time.second;

  return resultInDays * CALENDAR_SECONDS_PER_DAY + secondOffset;
}
