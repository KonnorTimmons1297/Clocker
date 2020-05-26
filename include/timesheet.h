#include <vector>

using std::vector;

enum class ClockAction {
    In,
    Out
};

class ClockEvent {
public:
    int hour, minute;
    ClockAction action;
};

class ClockRecord {
public:
    int year, month, day;
    vector<ClockEvent> events;

public:
    bool is_today() const;
};

class Timesheet {
public:
    char *file_name;
    int start_year, end_year;
    int start_month, end_month;
    int start_day, end_day;
    vector<ClockRecord> records;
};