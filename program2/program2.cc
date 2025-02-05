// Copyright 2024 leadbitr
#include"program2functions.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int m1, d1, y1, m2, d2, y2, count = 0;
  char c1, c2, c3, c4;
  cin >> m1 >> c1 >> d1 >> c2 >> y1;
  cin >> m2 >> c3 >> d2 >> c4 >> y2;
  bool after1 = false;
  if (ValidDate(m1, d1, y1) == true && ValidDate(m2, d1, y2) == true) {
    int tempD = d1, tempM = m1, tempY = y1;
    if (y2  > y1) {
      after1 = true;
    } else if (y2 == y1) {
      if (m2 > m1) {
        after1 = true;
      } else if (m2 == m1) {
        if (d2 > d1) {
          after1 = true;
        } else if (d2 == d1) {
          cout << m1 << "/" << d1 << "/" << y1 << " is 0 days before "
               << m2 << "/" << d2 << "/" << y2 << endl;
          return 0;
        }
      }
    }
    while (tempD != d2 || tempM != m2 || tempY != y2) {
      if (after1)
        NextDate(tempM, tempD, tempY);
      else
        PreviousDate(tempM, tempD, tempY);
      ++count;
    }
    if (after1)
      cout << m1 << "/" << d1 << "/" << y1 << " is " << count << " days before "
           << m2 << "/" << d2 << "/" << y2 << endl;
    else
      cout << m1 << "/" << d1 << "/" << y1 << " is " << count << " days after "
           << m2 << "/" << d2 << "/" << y2 << endl;
  }
  if (ValidDate(m1, d1, y1) == false)
    cout << m1 << "/" << d1 << "/" << y1 << " is not a valid date" << endl;
  if (ValidDate(m2, d2, y2) == false)
    cout << m2 << "/" << d2 << "/" << y2 << " is not a valid date" << endl;
  return 0;
}
