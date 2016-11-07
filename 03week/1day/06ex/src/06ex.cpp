#include <iostream>

using namespace std;

/**
 * Create a function called "fliter_greater_than_5" that takes a pointer to an int array, and it's size.
 * It should return a pointer to a new array that only consists the numbers that are bigger than 5.
 */

int* createArray(int size) {
  int* array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = i;
  }
  return array;
}

int* filterGreaterThanFive(int* array, int size) {
  int moreThanFive;
  for (int i = 0; i < size; i++) {
    if (array[i] > 5) {
      moreThanFive++;
    }
  }
  int* newArray = new int[moreThanFive];
  int newArrayIndex = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > 5) {
      newArray[newArrayIndex] = array[i];
      newArrayIndex++;
    }
  }
  delete array;
  array = NULL;
  return newArray;
}

int main() {
  int* gt5 = filterGreaterThanFive(createArray(10), 10);
  for (int i = 0; i < sizeof(gt5)/sizeof(int); i++) {
    cout << i << " : " << gt5[i] << endl;
  }
  delete gt5;
  gt5 = NULL;
  return 0;
}
