#include <vector>

using std::vector;

enum class ClockAction {
    In,
    Out
};

class ClockEvent {
    int hour, minute;
    ClockAction action;
};

class ClockRecord {
    int year, month, day;
    vector<ClockEvent> events;
};

class Timesheet {
    char *file_name;
    int start_year, end_year;
    int start_month, end_month;
    int start_day, end_day;
    vector<ClockRecord> records;
};