/**
 * Modern Gregorian calendar based breakdown and combination support to replace
 * C stdlib functions gmtime, localtime, mktime
 *
 * Copyright 2017 Aleksandr Koltsoff (czr@iki.fi)
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

void Calendar_breakdown(uint32_t secondsSinceEpoch, Calendar* output) {

  Calendar_breakdownDate(secondsSinceEpoch / CALENDAR_SECONDS_PER_DAY,
                         &output->date);
  Calendar_breakdownTime(secondsSinceEpoch % CALENDAR_SECONDS_PER_DAY,
                         &output->time);
}

void Calendar_breakdownTime(uint32_t secondsSinceMidnight, CalendarTime* output) {
  output->second = secondsSinceMidnight % 60;
  secondsSinceMidnight /= 60;
  output->minute = secondsSinceMidnight % 60;
  secondsSinceMidnight /= 60;
  output->hour = secondsSinceMidnight;
}

// Days per month (without including leap year extra day in February)
// Deltaspace = 4, so we could get away with a 2 bits per month encoding
//   TODO: Test the 2-bits per month encoding (will increase code size)
//         most likely to get to the correct value, but savings in this
//         table would be 12 bytes -> 3 bytes (9 bytes saved)
static const uint8_t sDaysPerMonth[12] = {
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// Days in a common year (sum(sDaysPerMonth))
#define DAYS_PER_COMMON_YEAR (365)
// Days in a leap year
#define DAYS_PER_LEAP_YEAR (DAYS_PER_COMMON_YEAR + 1)
// Days in a four year cycle starting with a leap year
#define DAYS_PER_LEAP_CYCLE (DAYS_PER_COMMON_YEAR * 3 + DAYS_PER_LEAP_YEAR)

// No leap day in year 2100 (unixtime point at which the leap
// year would be added)
#define NO_LEAP_CUTOFF_2100 (((2100 - 1970) + (31+29)) * CALENDAR_SECONDS_PER_DAY)

void Calendar_breakdownDate(uint32_t daysSinceEpoch, CalendarDate* output) {
  // range of daysSinceEpoch: 0-49710 (2**32 / 86400)

  // Rules:
  //   Year divisible by 4 = leap year
  //     Except for years divisible by 100
  //       Except for years divisible by 400 (2000 is one such year)
  // Our range is 1970 - 2106, so we need to deal with all corner cases
  //  2000 = include adjustment
  //  2100 = do not include adjustment

  // If we're beyond 2100, then decrement the number of daysSinceEpoch by one
  // to offset the missing leapyear
  // After this we can just use the /4 rule
  if (daysSinceEpoch >= NO_LEAP_CUTOFF_2100) {
    // since one leap day will be added anyway, shift this down
    daysSinceEpoch -= 1;
  }

  // range for years: 0-137
  // range for quadYears = 0-34
  // range for remYears = 0-3
  uint32_t quadYears = daysSinceEpoch / DAYS_PER_LEAP_CYCLE;
  uint32_t remYears = (daysSinceEpoch % DAYS_PER_LEAP_CYCLE) / DAYS_PER_COMMON_YEAR;

  // days since new year
  uint32_t remDays = daysSinceEpoch - 
                     (quadYears * DAYS_PER_LEAP_CYCLE +
                      remYears * DAYS_PER_COMMON_YEAR);

  // would be nice to find an O(1) for this
  uint8_t isLeap = (remYears == 0);
  uint8_t monthIdx = 0;
  while (monthIdx < 11) {
    uint8_t daysInMonth = sDaysPerMonth[monthIdx];
    if (monthIdx == 1 && isLeap) {
      daysInMonth += 1;
    }
    if (remDays < daysInMonth) {
      break;
    }
    remDays -= daysInMonth;
    monthIdx += 1;
  }

  output->year = quadYears * 4 + remYears;
  output->month = monthIdx;
  output->day = remDays;
}

uint8_t Calendar_getDayOfWeek(uint32_t secondsSinceEpoch) {
  // Unix epoch was a Thursday
  return (4 + (secondsSinceEpoch / CALENDAR_SECONDS_PER_DAY)) % 7;
}