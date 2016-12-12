#include <iostream>

// Create a function like macro that takes one argument.
// If the argument is false, it should print out the following:
// The expression in the argument. And the file name and the line in the file.

#define printIfFalse(a) a ? : cout << "value: " << #a << " in: " << __FILE__ << " line:" << __LINE__ << endl;

using namespace std;

int main() {
  int a = 1;
  int b = 2;
  printIfFalse(a > b);

  return 0;
}
