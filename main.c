//
// Created by Jeferson on 17/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main() {
    char file_name[MAX_LENGTH_NAME_FILE];       // and hopefully no one has a super long file name
    ScheduleEntry schedule[MAX_LINES];
    printf("Please enter the file name where your schedule is.\nThe file should be a CSV and don't forget "
           "to include the extension (i.e: .csv): ");
    get_input(file_name);
    int entryCount = readSchedule(file_name, schedule, MAX_LINES);

    while (entryCount == 0) {
        printf("Enter again the name of the file: ");
        get_input(file_name);
        entryCount = readSchedule(file_name,schedule, MAX_LINES);
    }
    printf("File [%s] opened successfully.\n", file_name);
    // Sort the schedule by time
    qsort(schedule, entryCount, sizeof(ScheduleEntry), compareByTime);

    char dayInput[MAX_DAY];
    while (1) {
        printf("\nEnter day in lowercase to check the schedule (or 'stop' to exit): ");
        get_input(dayInput);
        if (strcmp(dayInput, "stop") == 0) {
            break;
        }
        if (!ValidationDay(dayInput)) {
            printf("Wrong day input in '%s', please check for typos or capital letters.\n", dayInput);
            continue;
        }
        printf("---------------------------------------------------------------------\n");
        printf("On %s you have:\n", dayInput);
        printf("---------------------------------------------------------------------\n");

        int classesFound = 0;
        for (int i = 0; i < entryCount; i++) {
            if (strcmp(schedule[i].day, dayInput) == 0) {
                printf("%5s\t| %-50s|  %s\n", schedule[i].time, schedule[i].course, schedule[i].room);
                classesFound = 1;
            }
        }
        if (!classesFound) {
            printf("\t| No classes, but you should go to study C programming in IoT\n");
        }
    }

    return 0;
}

