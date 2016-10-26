#include <iostream>

using namespace std;

int main() {
  int high_number = 6655;
  int low_number = 2;

  int* high_number_pointer = &low_number;
  int* low_number_pointer = &high_number;
  // Please fix the problem and swap where the pointers point,
  // without using the "&" operator.

  cout << "original high: " << high_number_pointer << endl;
  cout << "original low: " << low_number_pointer << endl;

  int* temporary_number_pointer = high_number_pointer;
  high_number_pointer = low_number_pointer;
  low_number_pointer = temporary_number_pointer;

  cout << "high: " << high_number_pointer << endl;
  cout << "low: " << low_number_pointer;

  return 0;
}
