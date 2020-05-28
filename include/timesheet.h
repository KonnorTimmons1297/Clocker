#include <vector>
#include <string>

using std::vector;
using std::string;

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
    int start_year = -1, end_year = -1;
    int start_month = -1, end_month = -1;
    int start_day = -1, end_day = -1;
    vector<ClockRecord> records;
public:
    Timesheet() = default;
    Timesheet(string time_sheet_name);

    string generate_name();

    bool save();

private:
    void deserialize(const string& timesheet_data);
    std::string serialize();
    static std::string generateRecordKey(ClockRecord & record);
    static std::string generateEventKey(ClockEvent & event);
};