//
// Created by Jeferson on 17/10/2023.
//
#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#define MAX_DAY 20
#define MAX_TIME 10
#define MAX_COURSE 50
#define MAX_ROOM 20
#define MAX_LENGTH_NAME_FILE 30     //Length of the file
#define MAX_LINES 100               //the csv file should not be more than 100 rows
#define MAX_LENGTH_LINE 1024        // Assuming no line will be longer than 1024 characters

typedef struct {
    char day[MAX_DAY];
    char time[MAX_TIME];
    char course[MAX_COURSE];
    char room[MAX_ROOM];
} ScheduleEntry;

// Function to read the schedule from a CSV file
int readSchedule(const char *file_name, ScheduleEntry schedule[], int maxEntries);
//Function to write input handling possible error for spaces
void get_input(char *input);
//Function to verify that the user input is a valid day of the week
int ValidationDay(const char *dayInput);
// Function to compare ScheduleEntries by time in case there is more than one class in one day
int compareByTime(const void *a, const void *b);

#endif //PROJECT_LIBRARY_H
