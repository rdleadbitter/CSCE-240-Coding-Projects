// Copyright 2024 leadbitr

#ifndef _RIGHT_ISOSCELES_H_
#define _RIGHT_ISOSCELES_H_

#include"PixelShape.h"
#include<string>
using std::string;

namespace CSCE240_Program6 {

class RightIsosceles : public PixelShape {
 public:
  explicit RightIsosceles(int = 2, char = '*');
  virtual ~RightIsosceles() {}
  void SetLeg(int);
  int GetLeg() { return leg_; }
  virtual RightIsosceles& operator *= (double);
  virtual void Print(bool = true);
 private:
  int leg_;
};

}  // namespace CSCE240_Program6

#endif
