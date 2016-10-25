#include <iostream>
#include <string>

using namespace std;

int arrayMin(int array[], int arrayLength) {
	int min = array[0];
	for (int i = 1; i < arrayLength; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

int main() {
  int numbers[] = {7, 5, 8, -1, 2};
  // Write a function that takes an array and its length returns the minimal element
  // in the array (your own min function)
  cout << arrayMin(numbers, 5);
  return 0;
}
