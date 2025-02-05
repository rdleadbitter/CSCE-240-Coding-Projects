// Copyright 2024 leadbitr
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

bool isPrime(int num) {
  for (int i = 2; i < num; ++i) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool isFactor(int num, int div) {
  if (num % div == 0)
    return true;
  else
    return false;
}

bool isPrimeFactor(int num, int div) {
  if (isPrime(div)) {
    if (isFactor(num, div))
      return true;
    else
      return false;
  }
  return false;
}

int pow(int base, int power) {
  int ret = base;
  for (int i = 1; i < power; i++)
    ret *= base;
  return ret;
}

// Outputs the correct prime factorization of a given number
void corrector(int num) {
  cout << num << " = ";
  if (num > 0) {
    cout << "1";
  } else if (num < 0) {
    cout << "-1";
    num *= -1;
  }
  for (int i = 2; i < num; ++i) {
    if (isPrimeFactor(num, i)) {
      int temp = num, count = 0;
      bool go = true;
      while (go) {
        if (isFactor(temp, i)) {
          count++;
          temp /= i;
        } else {
          go = false;
        }
      }
      cout << " * " << i << "^" << count;
    }
  }
}

int main() {
  char eq, as;
  int num1, num2, product, pro = 1;
  bool done = false, invalid = false;
  // Expect first integer, =, +/- 1, and *
  cin >> num1 >> eq >> num2 >> as;
  if (cin.fail()) {
    invalid = true;
  } else {
    product = num1;
    if (product == 0) {
      invalid = true;
    } else {
      if (product < 1) {
        pro *= -1;
      }
      if (eq != '=') {
        invalid = true;
      } else {
        if (num2 != 1 && num2 != -1) {
          invalid = true;
        } else {
          if (as != '*') {
            invalid = true;
          } else {
            // Enter prime factors after +/- 1
            do {
              int base, power;
              char exp, q;
              cin >> base >> exp >> power >> q;
              if (cin.fail()) {
                invalid = true;
                done = true;
              } else {
                if (isPrimeFactor(product, base) == false) {
                  invalid = true;
                  done = true;
                } else {
                  if (exp != '^') {
                    invalid = true;
                    done = true;
                  } else {
                    if (isFactor(product, pow(base, power)) == false) {
                      done = true;
                    } else {
                      if (q == '?') {
                        pro *= pow(base, power);
                        done = true;
                      } else if (q == '*') {
                        pro *= pow(base, power);
                      } else {
                        invalid = true;
                        done = true;
                      }
                    }
                  }
                }
              }
            } while (done == false);
            if (invalid == false) {
              if (product == pro) {
                cout << "Correct!" << endl;
              } else {
                cout << "Incorrect. ";
                corrector(product);
                cout << endl;
              }
            }
          }
        }
      }
    }
  }
  if (invalid == true)
    cout << "Invalid input format." << endl;
  return 0;
}
