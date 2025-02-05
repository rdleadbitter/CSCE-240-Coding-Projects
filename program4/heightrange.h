// Copyright 2024 leadbitr

#ifndef HEIGHT_RANGE_H_
#define HEIGHT_RANGE_H_

#include<iostream>
using std::cout;
using std::ostream;
#include<string>
using std::string;
#include"height.h"

class HeightRange {
 public:
  void SetShortest(const Height&);

  Height GetShortest();

  void SetTallest(const Height&);

  Height GetTallest();

  HeightRange();

  HeightRange(const Height&, const Height&);

  bool InRange(const Height&, bool = true);

  Height Width();

 private:
  Height smallest_height;
  Height largest_height;
};

#endif
