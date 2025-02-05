#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void Print(bool fill, int length_, int width_, char pixel) {
  cout << "rectangle" << endl;
  for (int i = 1; i <= length_; ++i) {
    for (int j = 1; j <= width_; ++i) {
      if (i == 1 || i == length_) {
        cout << pixel;
      } else {
        if (j == 1 || j == width_) {
          cout << pixel;
        } else {
          if (fill)
            cout << pixel;
        }
      }
    }
    cout << endl;
  }
}
int main() {
  Print(true, 4, 5, '*');
  return 0;
}