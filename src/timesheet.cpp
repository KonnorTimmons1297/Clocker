#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "timesheet.h"
#include "json.h"
#include "date_time.h"

namespace fs = std::filesystem;

using json = nlohmann::json;
using std::fstream;
using std::string;

static const string TIME_SHEET_DIR = "/home/konnor/.clocker/timesheets";

static const string KEY_START_DAY = "START_DAY";
static const string KEY_START_MONTH = "START_MONTH";
static const string KEY_START_YEAR = "START_YEAR";
static const string KEY_END_DAY = "END_DAY";
static const string KEY_END_MONTH = "END_MONTH";
static const string KEY_END_YEAR = "END_YEAR";
static const string KEY_RECORDS = "RECORDS";

bool ClockRecord::is_today() const {
    DateTime time;
    return year == time.year && month == time.month && day == time.day;
}

Timesheet::Timesheet(string time_sheet_name) {
    string timesheet_file_path =
            TIME_SHEET_DIR + fs::path::preferred_separator + time_sheet_name;

    fstream timesheet_file(timesheet_file_path, std::ios::in);

    //Getting File size
    timesheet_file.seekg(0, std::ios::end);
    auto file_size = timesheet_file.tellg();
    timesheet_file.seekg(0, std::ios::beg);

    if(file_size > 0) {
        std::unique_ptr<char> timesheet_data(new char[file_size]);
        timesheet_file >> *timesheet_data;
        deserialize(timesheet_data.get());
    }
}

bool Timesheet::save() {
    return false;
}

string Timesheet::generate_name() {
    return std::to_string(start_day) + "/" + std::to_string(start_month) + "/" + std::to_string(start_year) + ".t";
}

void Timesheet::deserialize(const string& timesheet_data) {
    auto j = json::parse(timesheet_data);

    start_day = j[KEY_START_DAY];
    start_month = j[KEY_START_MONTH];
    start_year = j[KEY_START_YEAR];
    end_day = j[KEY_END_DAY];
    end_month = j[KEY_END_MONTH];
    end_year = j[KEY_END_YEAR];

    //DESERIALIZE THE MESS BELOW
}

string Timesheet::serialize() {
    json obj;

    obj[KEY_START_DAY] = start_day;
    obj[KEY_START_MONTH] = start_month;
    obj[KEY_START_YEAR] = start_year;
    obj[KEY_END_DAY] = end_day;
    obj[KEY_END_MONTH] = end_month;
    obj[KEY_END_YEAR] = end_year;

    for(ClockRecord record : records) {
        string record_key = generateRecordKey(record);

        for(ClockEvent event : record.events) {
            string event_key = generateEventKey(event);
            string action;
            if(event.action == ClockAction::In) {
                action = "in";
            } else {
                action = "out";
            }
            obj[KEY_RECORDS][record_key][event_key] = action;
        }

    }

    return obj.dump();
}

string Timesheet::generateRecordKey(ClockRecord &record) {
    return std::to_string(record.day) + "_" + std::to_string(record.month) + "_" + std::to_string(record.year);
}

string Timesheet::generateEventKey(ClockEvent & event) {
    return std::to_string(event.hour) + "_" + std::to_string(event.minute);
}