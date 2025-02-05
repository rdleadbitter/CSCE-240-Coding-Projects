// add your code here
// Copyright 2024 leadbitr

#include"truefalsequestion.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace csce240_program5 {

TrueFalseQuestion::TrueFalseQuestion(string q, bool tf) {
  answer_ = tf;
  SetQuestion(q);
}

void TrueFalseQuestion::SetAnswer(bool tf) {
  answer_ = tf;
}

void TrueFalseQuestion::Print(bool tf) const {
  cout << "Question: " << GetQuestion() << endl;
  if (tf) {
    cout << "Correct Answer: ";
    if (answer_)
      cout << "true";
    else
      cout << "false";
    cout << endl;
  }
}

}  // namespace csce240_program5
