#include <iostream>

using namespace std;

int counter(int from, int to, int step) {
  return (to - from)/step;
}

int* range(int from, int to, int step) {
  int* pointer = new int[counter(from, to, step)];
  for (int i = 0; i < counter(from, to, step); i++) {
      pointer[i] = from + i*step;
  }
  return pointer;
}

/**
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 3, 4, 5, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
  cout << range(-8, 2, 3)[0] << range(-8, 2, 3)[1] << range(-8, 2, 3)[2];
  return 0;
}
