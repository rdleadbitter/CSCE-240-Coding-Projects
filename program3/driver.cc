#include"program3functions.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() { 
  const int kRows = 4;
  double array[kRows][10] = {{1.2, 8.7, 4.1, 6.7, 7.1, 0.7, 0.3, 9.4, 6.4, 5.2},
                             {2.9, 2.4, 2.3, 2.1, 1.9, 3.4, 0.6, 1.8, 1.7, 2.2},
                             {5.7, 8.7, 2.3, 7.2, 3.3, 2.1, 1.6, 4.4, 5.5, 6.6},
                             {0.5, 3.5, 4.1, 1.6, 2.5, 3.9, 0.5, 1.8, 5.6, 5.2}};
  for (int i=0; i < 10; i++) {
    double a[2] ={-1, -1};
    double x = ModeInCol(array, kRows, i, a);
    cout << "The mode in column " << i << " is " << x << endl;
    cout << "a[0] = " << a[0] << ", a[1] = " << a[1] << endl;
  }
}