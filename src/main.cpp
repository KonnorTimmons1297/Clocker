#include <iostream>

#include "clocker_config.h"
#include "date_time.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "usage: clocker <in/out>" << std::endl;
        exit(1);
    }

    ClockAction action;

    string str_action(argv[1]);

    if (str_action == "in") {
        std::cout << "Clocking in\n";
        action = ClockAction::In;
    } else if (str_action == "out") {
        std::cout << "Clocking out\n";
        action = ClockAction::Out;
    } else {
        std::cout << "Invalid command: " << str_action << std::endl;
        exit(2);
    }

    ClockerConfig config;

    if (config.first_open) {
        std::cout << "Hello, what is your name?\n  => ";
        std::cin >> config.user_name;
        std::cout << "Welcome to Clocker, " << config.user_name << "!\n";
    }

    DateTime current_time;

    std::cout << "Current time: " << current_time << "\n";

    config.save();

    return 0;
}