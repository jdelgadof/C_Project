//
// Created by Jeferson on 17/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int readSchedule(const char *file_name, ScheduleEntry schedule[], int maxEntries) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "'%s' file not found or unable to open, check and try again.\n", file_name);
        return 0;
    }

    int entryCount = 0;
    char line[MAX_LENGTH_LINE];
    size_t lineLength;

    while (fgets(line, sizeof(line), file) && entryCount < maxEntries) {

        lineLength = strcspn(line, "\n");
        if (lineLength > 0) {
            line[lineLength] = '\0';
        }

        char *SeparatingComa = strtok(line, ",");
        if (SeparatingComa != NULL) {
            // Convert the day name to lowercase before storing, to make the comparisons easier
            char lowercaseDay[MAX_DAY];
            strcpy(lowercaseDay, SeparatingComa);
            for (int i = 0; lowercaseDay[i]; i++) {
                lowercaseDay[i] = tolower(lowercaseDay[i]);
            }
            strcpy(schedule[entryCount].day, lowercaseDay);
            SeparatingComa = strtok(NULL, ",");
            strcpy(schedule[entryCount].time, SeparatingComa);
            SeparatingComa = strtok(NULL, ",");
            strcpy(schedule[entryCount].course, SeparatingComa);
            SeparatingComa = strtok(NULL, ",");
            strcpy(schedule[entryCount].room, SeparatingComa);
            entryCount++;
        }
    }
    fclose(file);
    return entryCount;
}
int ValidationDay(const char *dayInput) {
    const char *validDays[] = { "monday",
                                "tuesday",
                                "wednesday",
                                "thursday",
                                "friday",
                                "saturday",
                                "sunday" };
    for (int i = 0; i < sizeof(validDays) / sizeof(validDays[0]); i++) {
        if (strcmp(dayInput, validDays[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
void get_input(char *input){
    fgets(input, MAX_LENGTH_NAME_FILE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
}
int compareByTime(const void *a, const void *b) {
    ScheduleEntry *entryA = (ScheduleEntry *)a;
    ScheduleEntry *entryB = (ScheduleEntry *)b;

    int A_hour, A_minute;
    int B_hour, timeB_minute;

    // Parse the time strings from entries
    sscanf(entryA->time, "%d:%d", &A_hour, &A_minute);
    sscanf(entryB->time, "%d:%d", &B_hour, &timeB_minute);

    // Compare based on time
    if (A_hour != B_hour) {
        return A_hour - B_hour;
    } else {
        return A_minute - timeB_minute;
    }
}
