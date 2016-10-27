#include <iostream>
#include <cmath>

using namespace std;

void drawDiamond(int number) {
  if (number%2 == 1) {
    number = floor(number/2)*2;
  }
  for (int i = 0; i < number/2; i++) {
    for (int j = 0; j < (number/2-i); j++) {
      cout << " ";
    }
    for (int k = 0; k < i*2+1; k++) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 0; i < number/2+1; i++) {
      for (int j = 0; j < i; j++) {
        cout << " ";
      }
      for (int k = 0; k < (number-i*2)+1; k++) {
        cout << "*";
      }
      cout << endl;
  }
}

int main() {
  // Create a function that takes a number and prints a diamond like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //  *********
  //   *******
  //    *****
  //     ***
  //      *
  //
  // The diamond should have as many lines as the value in the argument

  int lines = 9;
  drawDiamond(lines);

  return 0;
}
