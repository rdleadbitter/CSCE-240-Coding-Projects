// Copyright 2024 leadbitr

#include"RightIsosceles.h"
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Program6 {

  RightIsosceles::RightIsosceles(int l, char p) :
  PixelShape("right isosceles triangle", p) {
    leg_ = 2;
    if (l >= 2)
      leg_ = l;
  }

  void RightIsosceles::SetLeg(int l) {
    if (l >= 2)
      leg_ = l;
  }

  RightIsosceles& RightIsosceles::operator *= (double n) {
    if (leg_ * n >= 2) {
      leg_ *= n;
    }
    return *this;
  }

  void RightIsosceles::Print(bool fill) {
    char p = GetPixel();
    cout << GetName() << endl;
    for (int i = 1; i <= leg_; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (i == 1 || i == leg_) {
          cout << p << " ";
        } else {
          if (j == 1 || j == i) {
            cout << p << " ";
          } else {
            if (fill)
              cout << p << " ";
            else
              cout << "  ";
          }
        }
      }
      cout << endl;
    }
  }
}  // namespace CSCE240_Program6
