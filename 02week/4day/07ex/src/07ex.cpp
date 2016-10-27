#include <iostream>

using namespace std;

void drawHalfXmasTree(int number) {
  for (int i = 0; i < number; i++) {
    for (int x = 0; x < i+1; x++) {
      cout << "*";
    }
    cout << endl;
  }
}

int main() {
  // create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument

  int lineNumbers = 5;
  drawHalfXmasTree(lineNumbers);

  return 0;
}
