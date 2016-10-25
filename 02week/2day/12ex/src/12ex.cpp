#include <iostream>
#include <string>

using namespace std;

int sumArray(int array[], int arrayLength) {
	int sum;
//	int arrayLength = sizeof(array)/4;
	for (int i = 0; i < arrayLength; i++) {
		sum += array[i];
	}
	return sum;
}

int main() {
  int numbers[] = {4, 5, 6, 7, 8, 9, 10};
  // write your own sum function
  // it should take an array and it's length
  cout << sumArray(numbers, 7);
  return 0;
}
