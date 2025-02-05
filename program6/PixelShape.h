// Copyright 2024 leadbitr
#ifndef _PIXEL_SHAPE_H_
#define _PIXEL_SHAPE_H_

#include<string>
using std::string;

namespace CSCE240_Program6 {

class PixelShape {
 public:
  explicit PixelShape(string = "?", char = '*');
  virtual ~PixelShape() {}
  void SetName(string);
  void SetPixel(char);
  string GetName() { return name_; }
  char GetPixel() { return pixel_; }
  virtual void Print(bool = true);
  virtual PixelShape& operator *=(double) = 0;

 private:
  string name_;
  char pixel_;
};

}  // namespace CSCE240_Program6

#endif  // _PIXEL_SHAPE_H_
