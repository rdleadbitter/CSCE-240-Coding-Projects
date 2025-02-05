// Copyright 2024 leadbitr
#ifndef HEIGHT_H_
#define HEIGHT_H_

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::ostream;

class Height {
 public:
  bool SetValue(double);

  double GetValue() const { return value_; }

  bool SetUnits(string);

  string GetUnits() const { return units_; }

  void ConvertUnits(string);

  explicit Height(double = 0, string = "feet");

  // overload << operator to output height
  friend ostream& operator << (ostream& whereto, const Height&);

 private:
  double value_;
  string units_;
};

#endif
