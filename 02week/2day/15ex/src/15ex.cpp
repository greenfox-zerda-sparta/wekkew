#include <iostream>
#include <string>

using namespace std;

int indexOf(int array[], int arrayLength, int num) {
	int index = -1;
	for (int i = 0; i < arrayLength; i++) {
		if (array[i] == num) {
			index = i;
			break;
		}
	}
	return index;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes an array, its length and a number
  // and it returns the index of the given number in the array.
  // It should return -1 if did not find it. (linear search)
  cout << indexOf(numbers, 5, 5);
  return 0;
}
