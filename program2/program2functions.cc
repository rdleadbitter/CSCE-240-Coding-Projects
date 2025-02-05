// Copyright 2024 leadbitr
#include"program2functions.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

bool LeapYear(int year) {
  if (year % 400 == 0)
    return true;
  else if (year % 100 == 0)
    return false;
  else if (year % 4 == 0)
    return true;
  else
    return false;
}

int LastDayOfMonth(int month, int year) {
  if (month >= 1 && month <= 12) {
    if (month != 2) {
      if (month < 8 && month % 2 == 1)
        return 31;
      else if (month >= 8 && month % 2 == 0)
        return 31;
      else
        return 30;
    } else {
      if (year > 0) {
        if (LeapYear(year))
          return 29;
        else
          return 28;
      } else {
        return 0;
      }
    }
  } else {
      return 0;
    }
}

bool ValidDate(int month, int day, int year) {
  if (year > 0) {
    if (month >= 1 && month <= 12) {
      if (day >= 1 && day <= LastDayOfMonth(month, year)) {
        return true;
      }
    }
  }
  return false;
}

void NextDate(int& month, int& day, int& year) {
  if (ValidDate(month, day, year)) {
    if (day < LastDayOfMonth(month, year)) {
      ++day;
    } else {
      day = 1;
      if (month < 12) {
        ++month;
      } else {
        month = 1;
        ++year;
      }
    }
  }
}

void PreviousDate(int& month, int& day, int& year) {
  if (ValidDate(month, day, year)) {
    if (day > 1) {
      --day;
    } else {
      if (month > 1) {
        day = LastDayOfMonth(month-1, year);
        --month;
      } else {
        day = 31;
        month = 12;
        --year;
      }
    }
  }
}
