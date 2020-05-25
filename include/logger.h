#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void log_d(const char *message) {
    printf("%s\n", message);
}

#endif