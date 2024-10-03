/**
 * The Date class provides functionalities for creating, managing,
 * and comparing dates. It includes methods for constructing dates from integers
 * (month, day, and year) or a formatted string, checking leap years, validating
 * date inputs, and comparing dates (whether one is before, after, or equal to another).
 * Additionally, it provides a method to calculate the difference in days between
 * two Date objects.
 * @author          陳澤諒
 * @ID              B12505047
 * @Department      Engineering Science and Ocean Engineering
 * @Affiliation     National Taiwan University
 *
 * Date.h
 * version 1.0
 */

#include "Date.h"

/**
 *  Constructs a Date with the given month, day and year.   If the date is
 *  not valid, the entire program will halt with an error message.
 *  @param month is a month, numbered in the range 1...12.
 *  @param day is between 1 and the number of days in the given month.
 *  @param year is the year in question, with no digits omitted.
 *
 *  Grade: 15%
 */

Date ::Date(int month, int day, int year) {
    if (month < 1 || month > 12) {
        throw std::invalid_argument("Invalid month. Must be between 1 and 12.");
    }
    if (day < 1 || day > daysInMonth(month, year)) {
        throw std::invalid_argument("Invalid day for the given month and year.");
    }
    if (year <= 0) {
        throw std::invalid_argument("Invalid year. Must be positive.");
    }

    this->month = month;
    this->day = day;
    this->year = year;
}

/**
 *  Constructs a Date object corresponding to the given string.
 *  @param s should be a string of the form "month/day/year" where month must
 *  be one or two digits, day must be one or two digits, and year must be
 *  between 1 and 4 digits.  If s does not match these requirements or is not
 *  a valid date, the program halts with an error message.
 *
 *  Grade: 30%
 */
Date::Date(const string& s) {
    int m, d, y;
    char sep1, sep2;
    istringstream iss(s);

    // Parse the input string in the form of "month/day/year"
    if (!(iss >> m >> sep1 >> d >> sep2 >> y) || sep1 != '/' || sep2 != '/') {
        throw invalid_argument("Invalid date format. Expected format: month/day/year");
    }

    // Validate the extracted values
    if (!isValidDate(m, d, y)) {
        throw invalid_argument("Invalid date: " + s);
    }

    month = m;
    day = d;
    year = y;
}

/**
 *  Checks whether the given year is a leap year.
 *  @return true if and only if the input year is a leap year.
 *
 *  Grade: 10%
 */
bool Date::isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return true;
    }
    return false;
}

/**
 *  Returns the number of days in a given month.
 *  @param month is a month, numbered in the range 1...12.
 *  @param year is the year in question, with no digits omitted.
 *  @return the number of days in the given month.
 *
 *  Grade: 10%
 */
int Date::daysInMonth(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

/**
 *  Checks whether the given date is valid.
 *  @return true if and only if month/day/year constitute a valid date.
 *
 *  Years prior to A.D. 1 are NOT valid.
 *
 *  Grade: 20%
 */
bool Date::isValidDate(int month, int day, int year) {
    if (year < 1) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    int maxDays = daysInMonth(month, year);
    if (day < 1 || day > maxDays) {
        return false;
    }
    return true;
}

/**
 *  Returns a string representation of this Date in the form month/day/year.
 *  The month, day, and year are expressed in full as integers; for example,
 *  10/17/2010 or 5/11/258.
 *  @return a String representation of this Date.
 *
 *  Grade: 20%
 */
string Date::toString() {
    string res = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    return res;
}

/**
 *  Determines whether this Date is before the Date d.
 *  @return true if and only if this Date is before d.
 *
 *  Grade: 10%
 */
bool Date::isBefore(const Date& d) {
    if (this->year < d.year) {
        return true;
    }
    if (this->year > d.year) {
        return false;
    }
    if (this->month < d.month) {
        return true;
    }
    if (this->month > d.month) {
        return false;
    }
    if (this->day < d.day) {
        return true;
    }
    return false;
}

/**
 *  Determines whether this Date is after the Date d.
 *  @return true if and only if this Date is after d.
 *
 *  Grade: 10%
 */
bool Date::isAfter(const Date& d) {
    if (this->year > d.year) {
        return true;
    }
    if (this->year < d.year) {
        return false;
    }
    if (this->month > d.month) {
        return true;
    }
    if (this->month < d.month) {
        return false;
    }
    if (this->day > d.day) {
        return true;
    }
    return false;
}

/**
 *  Determines whether this Date is equal to the Date d.
 *  @return true if and only if this Date is the same as d.
 *
 *  Grade: 10%
 */
bool Date::isEqual(const Date& d) {
    if (this->year != d.year) {
        return false;
    }
    if (this->month != d.month) {
        return false;
    }
    if (this->day != d.day) {
        return false;
    }
    return true;
}

/**
 *  Returns the number of this Date in the year.
 *  @return a number n in the range 1...366, inclusive, such that this Date
 *  is the nth day of its year.  (366 is only used for December 31 in a leap
 *  year.)
 *
 *  Grade: 15%
 */
int Date::dayInYear() {
    int days = 0;
    for (int i = 1; i < this->month; i++) {
        days += daysInMonth(i, this->year);
    }
    days += this->day;
    return days;
}

/** Determines the difference in days between d and this Date.  For example,
 *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
 *  If this Date occurs before d, the result is negative.
 *  @return the difference in days between d and this Date.
 *
 *  Grade: 10%
 */

int Date::difference(const Date& d) {
    // Calculate the total number of days for both dates
    int totalDaysthis = 0;
    for (int i = 1; i < d.year; i++) {
        totalDaysthis += (isLeapYear(i)) ? 366 : 365;
    }
    totalDaysthis += const_cast<Date&>(d).dayInYear();
    int totalDaysD = 0;
    for (int i = 1; i < this->year; i++) {
        totalDaysD += (isLeapYear(i)) ? 366 : 365;
    }
    totalDaysD += this->dayInYear();
    return totalDaysD - totalDaysthis;
}