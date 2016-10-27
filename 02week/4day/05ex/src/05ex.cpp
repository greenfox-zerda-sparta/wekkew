#include <iostream>

using namespace std;

string hasNegative(int* array, int length) {
  for (int i = 0; i < length; i++) {
    if (array[i] < 0) {
      return "The array has negative number(s).";
    }
  }
  return "The array does not have any negative number.";
}

int main() {
  int numbers[] = {6, 5, -3, 4, -1, 8, 7};

  // Write a function that decides if an array includes at least one negative number or not
  int length = sizeof(numbers)/sizeof(int);
  cout << hasNegative(numbers, length);
  return 0;
}
