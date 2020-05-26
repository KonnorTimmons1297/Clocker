#include <iostream>

#include "clocker_config.h"
#include "date_time.h"

int main(int argc, char *argv[]) {
//    if (argc != 2) {
//        std::cout << "usage: clocker <in/out>" << std::endl;
//        exit(1);
//    }
//
    ClockAction clock_action;
//
//    string str_action(argv[1]);
//
//    if (str_action == "in") {
//        std::cout << "Clocking in\n";
//        clock_action = ClockAction::In;
//    } else if (str_action == "out") {
//        std::cout << "Clocking out\n";
//        clock_action = ClockAction::Out;
//    } else {
//        std::cout << "Invalid command: " << str_action << std::endl;
//        exit(2);
//    }

    ClockerConfig config;

    if (config.first_open) {
        std::cout << "Hello, what is your name?\n  => ";
        std::cin >> config.user_name;
        std::cout << "Welcome to Clocker, " << config.user_name << "!\n";
    }

    DateTime current_time;

    if(config.first_open) {
        Timesheet new_timesheet;
        new_timesheet.start_day = current_time.day;
        new_timesheet.start_month = current_time.month;
        new_timesheet.start_year = current_time.year;
        config.timesheets.emplace_back();
    }

    Timesheet current_timesheet = config.timesheets.back();

    ClockEvent clock_event {
        .hour =  current_time.hour,
        .minute =  current_time.minute,
        .action = clock_action
    };

    if(current_timesheet.records.empty() || !current_timesheet.records.back().is_today()) {
        ClockRecord new_record {
            .year = current_time.year,
            .month = current_time.month,
            .day = current_time.day,
        };
        current_timesheet.records.push_back(new_record);
    }

    ClockRecord current_record = current_timesheet.records.back();

    current_record.events.push_back(clock_event);

    std::cout << "Clock time: " << current_time << "\n";

    config.save();

    return 0;
}