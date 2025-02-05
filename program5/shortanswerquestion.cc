// add your code here
// Copyright 2024 leadbitr

#include"shortanswerquestion.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace csce240_program5 {

ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) {
  SetQuestion(q);
  answer_ = a;
}

void ShortAnswerQuestion::SetAnswer(string a) {
  answer_ = a;
}

void ShortAnswerQuestion::Print(bool tf) const {
  cout << "Question: " << GetQuestion() << endl;
  if (tf) {
    cout << "Correct Answer: " << answer_ << endl;
  }
}

}  // namespace csce240_program5
