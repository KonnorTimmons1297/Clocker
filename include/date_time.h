#include <iostream>
#include <ctime>

using std::ostream;

class DateTime {
public:
    long epoch_time;
    uint16_t year;
    uint8_t month, day;
    uint8_t hour, minute;
    bool pm;

public:
    DateTime() {
        time_t ttime = time(nullptr);
        epoch_time = ttime;
        std::cout << "Epoch Time: " << epoch_time << "\n";
        tm *local_time = localtime(&ttime);

        year = 1900 + local_time->tm_year;
        month = local_time->tm_mon + 1;
        day = local_time->tm_mday;

        hour = local_time->tm_hour % 12;
        pm = local_time->tm_hour / 12;
        minute = local_time->tm_min + 1;
    }

    friend ostream &operator<<(ostream &os, const DateTime &dt) {
        os << (int)dt.day << "/" << (int)dt.month << "/" << (int)dt.year << " " << (int)dt.hour << ":" << (int)dt.minute;
        if (dt.pm) {
            os << " PM";
        } else {
            os << " AM";
        }
        return os;
    }
};