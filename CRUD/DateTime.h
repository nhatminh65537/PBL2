#ifndef __DATETIME_H__
#define __DATETIME_H__

#define NONE -1

#include <string>
using namespace std;
class DateTime
{
    private:
        int year;
        int month;
        int day;
        int hour;
        int minute;
    public:
        DateTime(int year=NONE, int month=NONE, int day=NONE, int hour=NONE, int minute=NONE) :
            year(year), month(month), day(day), hour(hour), minute(minute) {}
        int getYear() const { return year; }
        int getMonth() const { return month; }
        int getDay() const { return day; }
        int getHour() const { return hour; }
        int getMinute() const { return minute; }

        void setYear(int year) { this->year = year; }
        void setMonth(int month) { this->month = month; }
        void setDay(int day) { this->day = day; }
        void setHour(int hour) { this->hour = hour; }
        void setMinute(int minute) { this->minute = minute; }

        friend bool operator==(const DateTime& lhs, const DateTime& rhs);
        friend bool operator< (const DateTime& lhs, const DateTime& rhs);
        friend bool operator> (const DateTime& lhs, const DateTime& rhs);

        static bool validate(int year, int month, int day, int hour, int minute);
        DateTime operator+(int minutes) const;
        DateTime operator-(int minutes) const;
        const string& toString() const;

        static DateTime now();
};

DateTime nullTime(NONE, NONE, NONE, NONE, NONE);

#endif
