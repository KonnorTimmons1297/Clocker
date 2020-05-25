#include <iostream>
#include <ctime>

using std::ostream;

class DateTime {
public:
    time_t epoch_time;
    int year, month, day;
    int hour, minute;
    bool pm;

public:
    DateTime() {
        time_t ttime = time(0);
        epoch_time = ttime;
        tm *local_time = localtime(&ttime);

        year = 1900 + local_time->tm_year;
        month = local_time->tm_mon + 1;
        day = local_time->tm_mday;

        hour = local_time->tm_hour % 12;
        pm = local_time->tm_hour / 12;
        minute = local_time->tm_min + 1;
    }

    friend ostream &operator<<(ostream &os, const DateTime &dt) {
        os << dt.day << "/" << dt.month << "/" << dt.year << " " << dt.hour << ":" << dt.minute;
        if (dt.pm) {
            os << " PM";
        } else {
            os << " AM";
        }
        return os;
    }
};