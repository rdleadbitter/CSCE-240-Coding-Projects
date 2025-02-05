// Copyright 2024 leadbitr

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include"PixelShape.h"
#include<string>
using std::string;

namespace CSCE240_Program6 {

class Rectangle : public PixelShape{
 public:
  explicit Rectangle(int = 2, int = 1, char = '*');
  virtual ~Rectangle() {}
  void SetLength(int);
  int GetLength() { return length_; }
  void SetWidth(int);
  int GetWidth() { return width_; }
  virtual Rectangle& operator *=(double);
  virtual void Print(bool = true);
 private:
  int length_;
  int width_;
};

}  // namespace CSCE240_Program6

#endif
