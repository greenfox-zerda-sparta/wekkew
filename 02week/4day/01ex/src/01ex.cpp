#include <iostream>
#include <string>

using namespace std;

void square(int* array, int length) {
	for (int i = 0; i < length; i++) {
		array[i] *= array[i];
		cout << array[i];
	}
}

int main() {
  // Write a function that takes an array and squares all the elements in the array
  int array[7] = {1, 2, 3, 4, 5, 6, 7};
  int length = sizeof(array)/sizeof(int);
  square(array, length);
  return 0;
}
