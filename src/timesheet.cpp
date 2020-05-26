#include "timesheet.h"

#include "date_time.h"

bool ClockRecord::is_today() const {
    DateTime time;
    return year == time.year && month == time.month && day == time.day;
}
