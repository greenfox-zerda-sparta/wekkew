#include <iostream>

// Take the function like macro from the previous exercise.
// Make it so, that it's defined like the way You wrote it
// when __DEBUG is defined.
// It's defined to be nothing otherwise.
#define __DEBUG

#ifdef __DEBUG
#define printIfFalse(a) a ? : cout << "value: " << #a << " in: " << __FILE__ << " line:" << __LINE__ << endl;
#else
#endif

using namespace std;

int main() {
  int a = 1;
  int b = 2;
  printIfFalse(a > b);
  printIfFalse(1 > 2);
  return 0;
}
