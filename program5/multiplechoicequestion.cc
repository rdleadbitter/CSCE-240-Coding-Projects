// Copyright 2024 leadbitr

#include"multiplechoicequestion.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace csce240_program5 {

// Parameterized, explicit constructor
MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int n, string * a,
                                               bool * c) : Question(q) {
  if (n >= 0)
    num_answers_ = n;
  else
    num_answers_ = 0;
  answers_ = nullptr;
  correct_ = nullptr;
  answers_ = new string[num_answers_];
  correct_ = new bool[num_answers_];
  if (a == nullptr && c == nullptr) {
    for (int i = 0; i < num_answers_; ++i) {
      answers_[i] = "";
      correct_[i] = true;
    }
  } else if (a != nullptr && c == nullptr) {
    for (int i = 0; i < num_answers_; ++i) {
      answers_[i] = a[i];
      correct_[i] = true;
    }
  } else {
    for (int i = 0; i < num_answers_; ++i) {
      answers_[i] = a[i];
      correct_[i] = c[i];
    }
  }
}

// copy constructor
MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& q)
                                             : Question(q.GetQuestion()) {
  num_answers_ = q.num_answers_;
  if (num_answers_ == 0) {
    answers_ = nullptr;
    correct_ = nullptr;
  } else {
  answers_ = new string[num_answers_];
  correct_ = new bool[num_answers_];
}
  for (int i = 0; i < num_answers_; ++i) {
    answers_[i] = q.answers_[i];
    correct_[i] = q.correct_[i];
  }
}

// destructor
MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  if (answers_ != nullptr)
    delete[] answers_;
  if (correct_ != nullptr)
    delete[] correct_;
}

// overloaded assignment operator
MultipleChoiceQuestion& MultipleChoiceQuestion::operator =
                        (const MultipleChoiceQuestion& q) {
  SetQuestion(q.GetQuestion());
  num_answers_ = q.num_answers_;
  if (answers_ != nullptr)
    delete [] answers_;
  if (correct_ != nullptr)
    delete [] correct_;
  if (num_answers_ == 0) {
    answers_ = nullptr;
    correct_ = nullptr;
  } else {
    answers_ = new string[num_answers_];
    correct_ = new bool[num_answers_];
  }
  for (int i = 0; i < num_answers_; ++i) {
    answers_[i] = q.answers_[i];
    correct_[i] = q.correct_[i];
  }
  return *this;
}

void MultipleChoiceQuestion::SetAnswerChoices(int n, string * a, bool * c) {
  delete [] answers_;
  delete [] correct_;
  answers_ = nullptr;
  correct_ = nullptr;
  num_answers_ = n;
  if (num_answers_ > 0) {
    answers_ = new string[num_answers_];
    if (answers_ != nullptr) {
      for (int i = 0; i < num_answers_; ++i)
        answers_[i] = a[i];
    } else {
      for (int i = 0; i < num_answers_; ++i)
        answers_[i] = "";
    }
    correct_ = new bool[num_answers_];
    if (correct_ != nullptr) {
      for (int i = 0; i < num_answers_; ++i)
        correct_[i] = c[i];
    } else {
      for (int i = 0; i < num_answers_; ++i)
        correct_[i] = true;
    }
  }
}

void MultipleChoiceQuestion::Print(bool tf) const {
  cout << "Question: " << GetQuestion() << endl;
  cout << "Answer Choices:" << endl;
  for (int i = 0; i < num_answers_; i++) {
    cout << answers_[i];
    if (tf) {
      if (correct_[i]) {
        cout << " - correct";
      } else {
        cout << " - incorrect";
      }
    }
    cout << endl;
  }
}

}  // namespace csce240_program5
