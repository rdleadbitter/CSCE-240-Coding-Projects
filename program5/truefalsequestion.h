// Copyright 2024 leadbitr
// TrueFalseQuestion should be a child of the Question class

// The class should have a private bool data member that holds whether the
// answer to the question is true or false. Add an accessor and mutator
// function for this data member

// Create an explicit constructor that allows the question and answer to be
// initialized when an object is instantiated. The question and answer
// parameters should have default arguments of "?" and true, respectively.

// Add a Print function that takes a bool parameter: void Print(bool) const;
// This function should create 1 or 2 lines of output to the standard output
// device, using cout.
// The first line of output should be "Question: " followed by the value of
// the question data member (from base class Question).
// If the Print function's argument is true, it should output a second line
// that is "Correct Answer: " followed by "true" or "false" depending on the
// value of the private data member.
// See testtf.cc for example function calls and /output/correcttf.txt for the
// expected output for those function calls.

#ifndef _HOME_LEADBITR_CSCE240_ASSIGNMENTS_PROGRAM5_TRUEFALSEQUESTION_H_
#define _HOME_LEADBITR_CSCE240_ASSIGNMENTS_PROGRAM5_TRUEFALSEQUESTION_H_

#include<string>
using std::string;
#include"question.h"

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
 public:
  explicit TrueFalseQuestion(string = "?", bool = true);
  bool GetAnswer() { return answer_; }
  void SetAnswer(bool);
  void Print(bool) const;

 private:
  bool answer_;
};

}  // namespace csce240_program5

#endif  // _HOME_LEADBITR_CSCE240_ASSIGNMENTS_PROGRAM5_TRUEFALSEQUESTION_H_
