// Copyright 2024 leadbitr
#ifndef PROGRAM_3_FUNCTIONS_H_
#define PROGRAM_3_FUNCTIONS_H_

const int kCols = 10;

int CountAboveAv(const double[][kCols], int);

void SortByCol(double[][kCols], int, int, bool);

void SortByRow(double[][kCols], int, int, bool);

double MedianInCol(double[][kCols], int, int);

double ModeInCol(double[][kCols], int, int, double[2]);

#endif
