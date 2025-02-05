// Copyright 2024 leadbitr
#include"program3functions.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// calculates average value of 2D double array and counts
// the number of elements greater than the average
int CountAboveAv(const double nums[][kCols], int rows) {
  double sum = 0, mean = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < kCols; ++j)
      sum += nums[i][j];
  }
  mean = sum/(kCols*rows);
  int count = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < kCols; ++j) {
      if (nums[i][j] > mean)
        count++;
    }
  }
  return count;
}

// Uses a bubble sort algorithm to sort the rows
// of an array based on a specific column
void SortByCol(double nums[][kCols], int rows, int col, bool updown) {
  for (int i = rows-1; i > 0; i--) {
    for (int j = 0; j < i; ++j) {
      if (updown == true) {
        if ( nums[j][col] > nums[j+1][col] ) {
          for (int k = 0; k < kCols; ++k) {
            double temp = nums[j][k];
            nums[j][k] = nums[j+1][k];
            nums[j+1][k] = temp;
          }
        }
      } else {
        if ( nums[j][col] < nums[j+1][col] ) {
          for (int k = 0; k < kCols; ++k) {
            double temp = nums[j][k];
            nums[j][k] = nums[j+1][k];
            nums[j+1][k] = temp;
          }
        }
      }
    }
  }
}

// Uses a bubble sort algorithm to sort the
// columns of an array based on a specific row
void SortByRow(double nums[][kCols], int rows, int row, bool updown) {
  for (int i = kCols-1; i > 0; i--) {
    for (int j = 0; j < i; ++j) {
      if (updown == true) {
        if ( nums[row][j] > nums[row][j+1] ) {
          for (int k = 0; k < rows; ++k) {
            double temp = nums[k][j];
            nums[k][j] = nums[k][j+1];
            nums[k][j+1] = temp;
          }
        }
      } else {
        if ( nums[row][j] < nums[row][j+1] ) {
          for (int k = 0; k < rows; ++k) {
            double temp = nums[k][j];
            nums[k][j] = nums[k][j+1];
            nums[k][j+1] = temp;
          }
        }
      }
    }
  }
}

// Sorts a column using SortByCol and returns the average of the middle
// two values if rows are even or returns the middle value if odd
double MedianInCol(double nums[][kCols], int rows, int col) {
  SortByCol(nums, rows, col, true);
  if (rows % 2 == 0)
    return (nums[rows/2-1][col]+nums[rows/2][col])/2;
  else if (rows % 2 == 1)
    return nums[rows/2][col];
  else
    return 0;
}

// Sorts a column ascending and counts occurences of each value in a 2D array
// Determines the maximum occuring value (1 or 2 occurences at most)
// Populates mode array based on maximum occurences
// and returns appropriate values
double ModeInCol(double nums[][kCols], int rows, int col, double mode[2]) {
  SortByCol(nums, rows, col, true);
  double occ[rows][2];
  int index = 0;
  for (int i = 0; i < rows; i++) {
    if (i == 0) {
      occ[0][0] = nums[0][col];
      occ[0][1] = 1;
    } else {
      if (nums[i][col] == nums[i-1][col]) {
        occ[index][1]++;
      } else {
        index++;
        occ[index][0] = nums[i][col];
        occ[index][1] = 1;
      }
    }
  }
  int max = 0, count = 0;
  for (int i = 0; i < index+1; i++) {
    if (occ[i][1] > max)
      max = occ[i][1];
  }
  for (int i = 0; i < index+1; i++) {
    if (occ[i][1] == max)
      count++;
  }
  if (count > 2) {
    return 0;
  } else {
    bool full = false;
    for (int i = 0; i < index+1; i++) {
      if (occ[i][1] == max) {
        if (count == 1) {
          mode[0] = occ[i][0];
          return 1;
        } else if (count == 2) {
          if (!full) {
            mode[0] = occ[i][0];
            full = true;
          } else {
            mode[1] = occ[i][0];
            return 2;
          }
        }
      }
    }
    return 1;
  }
}
