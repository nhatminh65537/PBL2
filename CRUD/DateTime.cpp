#include "DateTime.h"
#include <string>
#include <time.h>
using namespace std;

bool operator==(const DateTime& lhs, const DateTime& rhs) {
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day && lhs.hour == rhs.hour && lhs.minute == rhs.minute;
}

bool operator<(const DateTime& lhs, const DateTime& rhs) {
    if (lhs.year != -1 && rhs.year != -1) {
        if (lhs.year < rhs.year) return true;
        if (lhs.year > rhs.year) return false;
    }
    if (lhs.month != -1 && rhs.month != -1) {
        if (lhs.month < rhs.month) return true;
        if (lhs.month > rhs.month) return false;
    }
    if (lhs.day != -1 && rhs.day != -1) {
        if (lhs.day < rhs.day) return true;
        if (lhs.day > rhs.day) return false;
    }
    if (lhs.hour != -1 && rhs.hour != -1) {
        if (lhs.hour < rhs.hour) return true;
        if (lhs.hour > rhs.hour) return false;
    }
    if (lhs.minute != -1 && rhs.minute != -1) {
        if (lhs.minute < rhs.minute) return true;
        if (lhs.minute > rhs.minute) return false;
    }
    return true;
}

bool operator>(const DateTime& lhs, const DateTime& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

const string& DateTime::toString() const {
    static string str;
    str = to_string(hour) + ":" + to_string(minute) + " " + to_string(day) + "-" + to_string(month) + "-" + to_string(year);
    return str;
}

bool DateTime::validate(int year, int month, int day, int hour, int minute) {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return false;
    }
    if (month == 2) {
        if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
            if (day > 29) return false;
        } else {
            if (day > 28) return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) return false;
    }
    return true;
}

DateTime DateTime::operator+(int minutes) const {
    DateTime dt = *this;
    dt.minute += minutes;
    if (dt.minute >= 60) {
        dt.hour += dt.minute / 60;
        dt.minute %= 60;
    }
    if (dt.hour >= 24) {
        dt.day += dt.hour / 24;
        dt.hour %= 24;
    }
    if (dt.day > 31) {
        dt.month += dt.day / 31;
        dt.day %= 31;
    }
    if (dt.month > 12) {
        dt.year += dt.month / 12;
        dt.month %= 12;
    }
    return dt;
}

DateTime DateTime::operator-(int minutes) const {
    DateTime dt = *this;
    dt.minute -= minutes;
    if (dt.minute < 0) {
        dt.hour -= dt.minute / 60;
        dt.minute = 60 + dt.minute % 60;
    }
    if (dt.hour < 0) {
        dt.day -= dt.hour / 24;
        dt.hour = 24 + dt.hour % 24;
    }
    if (dt.day < 1) {
        dt.month -= dt.day / 31;
        dt.day = 31 + dt.day % 31;
    }
    if (dt.month < 1) {
        dt.year -= dt.month / 12;
        dt.month = 12 + dt.month % 12;
    }
    return dt;
}

DateTime DateTime::now() {
    time_t t = time(0);
    struct tm* now = localtime(&t);
    return DateTime(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min);
}
