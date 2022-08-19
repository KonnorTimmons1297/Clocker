#include <string.h> // strcmp()
#include <stdio.h> // File IO
#include <time.h>

static const char *TIMESHEET_FILENAME = "timesheet.txt";

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Expected command <in/out>\n");
        return(1);
    }

    char *command = argv[1];

    if (strcmp(command, "in") != 0 && strcmp(command, "out") != 0)
    {
        printf("Unknown command: %s\n", command);
        return(1);
    }

    time_t current_time       = time(NULL);
    char * local_current_time = asctime(localtime(&current_time));

    FILE *timesheet_csv_fp = fopen(TIMESHEET_FILENAME, "r+");

    if (timesheet_csv_fp == NULL)
    {
        printf("Timesheet file does not exist!\n");
        printf("Do you want to create it now? (y/n)\n");
        char *create_timesheet_response;
        scanf("%s", create_timesheet_response);
        if (strcmp(create_timesheet_response, "y") != 0)
        {
            printf("Unable to proceed without timesheet!\n");
            return(1);
        }
        timesheet_csv_fp = fopen(TIMESHEET_FILENAME, "w");
        if (timesheet_csv_fp == NULL)
        {
            printf("Failed to create new timesheet\n");
            return(1);
        }
    }
    fseek(timesheet_csv_fp, 0, SEEK_END);
    fprintf(timesheet_csv_fp, "%s@%s", command, local_current_time);
    fclose(timesheet_csv_fp);

    printf("%s@%s\n", command, local_current_time);

    return(0);
}
