#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int returnZero() {
  return 0;
}

int main() {
  // write a recursive function that can add numbers in
  // [1, 2, [3, 4], 1, [1, [2, 4]]]

  int*** array;
  array[0][0][0] = 1;
  array[1][0][0] = 2;
  array[2][0][0] = 3;
  array[2][0][1] = 4;
  array[3][0][0] = 5;
  array[3][1][0] = 6;
  array[3][1][1] = 7;

  system("pause");
  return 0;
}