// Copyright 2024 leadbitr

#include"height.h"

bool Height::SetValue(double v) {
  if (v > 0) {
    value_ = v;
  }
  return value_ == v;
}

bool Height::SetUnits(string u) {
  if (u == "inches" || u == "feet" || u == "centimeters" || u == "meters") {
    units_ = u;
  }
  return units_ == u;
}

void Height::ConvertUnits(string new_units) {
  if ( units_ == new_units || (new_units != "inches" &&
                               new_units != "feet" &&
                               new_units != "centimeters" &&
                               new_units != "meters") ) {
    return;
  } else {
    if (units_ == "inches") {
      if (new_units == "feet")
        value_ = value_ / 12;
      else if (new_units == "centimeters")
        value_ = value_ * 2.54;
      else
        value_ = value_ / 39.37008;
    } else if (units_ == "feet") {
      if (new_units == "inches")
        value_ = value_ * 12;
      else if (new_units == "centimeters")
        value_ = value_ * 30.48;
      else
        value_ = value_ / 3.28084;
    } else if (units_ == "centimeters") {
      if (new_units == "inches")
        value_ = value_ / 2.54;
      else if (new_units == "feet")
        value_ = value_ / 30.48;
      else
        value_ = value_ / 100;
    } else if (units_ == "meters") {
      if (new_units == "inches")
        value_ = value_ * 39.37008;
      else if (new_units == "feet")
        value_ = value_ * 3.28084;
      else
        value_ = value_ * 100;
    }
  }
  units_ = new_units;
}

Height::Height(double value, string units) {
  value_ = 0;  // default value
  units_ = "feet";  // default value
  SetValue(value);
  SetUnits(units);
}

ostream& operator << (ostream& whereto, const Height& right) {
  return whereto << right.value_ << right.units_;
}
