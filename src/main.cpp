#include "clocker.h"

void new_user();

int main() {
    ClockerConfig config;

    if (config.first_open) {
        new_user();
    } else {
        config.users.emplace_back("Jeff");
    }

    config.save();

    return 0;
}

void new_user() {

}