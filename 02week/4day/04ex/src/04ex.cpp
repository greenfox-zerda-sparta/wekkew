#include <iostream>
#include <cmath>

using namespace std;

void revereseArray(int* array, int length) {
  for (int i = 0; i < length; i++) {
    cout << i << ":" << array[i] << endl;
  }
  cout << "___________________" << endl;
  for (int i = 0; i < length/2; i++) {
    int temporary = array[i];
    array[i] = array[length-1-i];
    array[length-1-i] = temporary;
  }
  for (int i = 0; i < length; i++) {
    cout << i << ":" << array[i] << endl;
  }
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

  // Write a function that takes an array and its length than reverses the array
  int length = sizeof(array)/sizeof(int);
  revereseArray(array, length);

  return 0;
}
