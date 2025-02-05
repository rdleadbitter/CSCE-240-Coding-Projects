// Copyright 2024 leadbitr

#include"PixelShape.h"
#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;

namespace CSCE240_Program6 {

PixelShape::PixelShape(string n, char p) {
  name_ = "?";
  pixel_ = '*';
  if (n.length() > 0)
    name_ = n;
  if (p >= 33 && p <= 126)
    pixel_ = p;
}

void PixelShape::SetName(string n) {
  if (n != "")
    name_ = n;
}

void PixelShape::SetPixel(char p) {
  if (p >= 33 && p <= 126)
    pixel_ = p;
}

void PixelShape::Print(bool tf) {
  cout << name_ << endl;
}

}  // namespace CSCE240_Program6
