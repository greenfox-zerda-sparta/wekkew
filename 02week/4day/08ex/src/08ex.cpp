#include <iostream>

using namespace std;

void drawXMasTree(int numbers) {
  for (int i = 0; i < numbers; i++) {
    for (int j = 0; j < numbers-i; j++) {
      cout << " ";
    }
    for (int k = 0; k < i*2+1; k++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  // Create a function that takes a number and prints a triangle like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //
  // The triangle should have as many lines as the value in the argument

  int branches = 6;
  drawXMasTree(branches);

  return 0;
}
