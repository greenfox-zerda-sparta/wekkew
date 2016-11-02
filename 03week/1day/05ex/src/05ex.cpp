#include <iostream>

using namespace std;

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int* resize(int* array, int size, int newSize) {
  int* newArray = new int[newSize];
  for (int i = 0; i < newSize; i++) {
    if (i < size) {
      newArray[i] = array[i];
    }
    else {
      newArray[i] = 0;
    }
  }
  delete[] array;
  array = NULL;
  return newArray;
}

int main() {
  int* array = new int[3];
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  cout << resize(array, 3, 4)[3];
  return 0;
}
