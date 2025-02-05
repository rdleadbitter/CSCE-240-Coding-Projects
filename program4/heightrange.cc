// Copyright 2024 leadbitr
#ifndef HEIGHT_RANGE_CC_
#define HEIGHT_RANGE_CC_

#include"heightrange.h"

void HeightRange::SetShortest(const Height& h) {
  Height copy = h;  // creates copy of h in case units don't match
  if (h.GetUnits() != largest_height.GetUnits())
    copy.ConvertUnits(largest_height.GetUnits());
  if (copy.GetValue() <= largest_height.GetValue())
    smallest_height = h;
}

Height HeightRange::GetShortest() {
  Height ret = Height(smallest_height.GetValue(), smallest_height.GetUnits());
  return ret;
}

void HeightRange::SetTallest(const Height& h) {
  Height copy = h;  // creates copy of h in case units don't match
  if (h.GetUnits() != smallest_height.GetUnits())
    copy.ConvertUnits(smallest_height.GetUnits());
  if (h.GetValue() >= smallest_height.GetValue())
    largest_height = h;
}

Height HeightRange::GetTallest() {
  Height ret = Height(largest_height.GetValue(), largest_height.GetUnits());
  return ret;
}

// default constructor
HeightRange::HeightRange() {
  smallest_height.SetValue(0);
  largest_height.SetValue(0);
}

HeightRange::HeightRange(const Height& h1, const Height& h2) {
  Height copy = h2;  // creates copy of h2 in case units don't match h1
  if (h1.GetUnits() != h2.GetUnits()) {
    copy.ConvertUnits(h1.GetUnits());
  }
  if (h1.GetValue() > copy.GetValue()) {
    smallest_height = h2;
    largest_height = h1;
  } else {
    smallest_height = h1;
    largest_height = h2;
  }
}

bool HeightRange::InRange(const Height& h, bool endpoints) {
  Height minCopy = smallest_height;  // creates copy of smallest height
                                     // in case units don't match
  Height maxCopy = largest_height;  // creates copy of largest height
                                    // in case units don't match
  if (h.GetUnits() != smallest_height.GetUnits())
    minCopy.ConvertUnits(h.GetUnits());
  if (h.GetUnits() != largest_height.GetUnits())
    maxCopy.ConvertUnits(h.GetUnits());
  if (endpoints) {   // includes endpoints in comparison
    if (h.GetValue() >= minCopy.GetValue() &&
        h.GetValue() <= maxCopy.GetValue())
      return true;
    else
      return false;
  } else {  // doesn't include endpoints in comparison
    if (h.GetValue() > minCopy.GetValue() &&
        h.GetValue() < maxCopy.GetValue())
      return true;
    else
      return false;
  }
}

Height HeightRange::Width() {
  Height copy = smallest_height;  // creates copy of smallest height
                                  //  in case units don't match
  if (largest_height.GetUnits() != smallest_height.GetUnits()) {
    copy.ConvertUnits(largest_height.GetUnits());  //  width should have
                                                   //  largest height's units
  }
  double dif = largest_height.GetValue() - copy.GetValue();
  Height width = Height(dif, largest_height.GetUnits());
  return width;
}

#endif
