// Copyright 2024 leadbitr

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

#include"Rectangle.h"

namespace CSCE240_Program6 {

Rectangle::Rectangle(int l, int w, char p) : PixelShape("rectangle", p) {
  length_ = 2;
  width_ = 1;
  if (l > 0)
    length_ = l;
  if (w > 0)
    width_ = w;
}

void Rectangle::SetLength(int l) {
  if (l > 0)
    length_ = l;
}

void Rectangle::SetWidth(int w) {
  if (w > 0)
    width_ = w;
}

Rectangle& Rectangle::operator *=(double n) {
  if (length_ * n >= 1 && width_ * n >= 1) {
    length_ *= n;
    width_ *= n;
  }
  return *this;
}

void Rectangle::Print(bool fill) {
  char p = GetPixel();
  cout << GetName() << endl;
  for (int i = 1; i <= length_; ++i) {
    for (int j = 1; j <= width_; ++j) {
      if (i == 1 || i == length_) {
        cout << p << " ";
      } else {
        if (j == 1 || j == width_) {
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
