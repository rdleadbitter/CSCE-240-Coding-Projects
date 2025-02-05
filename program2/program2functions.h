//Copyright 2024 leadbitr
// header file with function prototypes
#ifndef _PROGRAM_2_FUNCTIONS_
#define _PROGRAM_2_FUNCTIONS_

bool LeapYear(int year);

int LastDayOfMonth(int month, int year = 0);

bool ValidDate(int month, int day, int year);

void NextDate(int& month, int& day, int& year);

void PreviousDate( int& month, int& day, int& year );

#endif