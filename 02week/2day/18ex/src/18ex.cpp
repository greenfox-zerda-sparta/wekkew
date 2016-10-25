#include <iostream>
using namespace std;

int evenArrayElements(int array[], int arrayLength) {
	int evenCounter = 0;
	for (int index = 0; index < arrayLength; index++) {
		if (array[index]%2 == 0) {
			evenCounter += 1;
		}
	}
	return evenCounter;
}

int main(){
  int numbers[] = {4, 5, 6, 2, 3, 8, 6, 5, 7};
  // create a function that takes an array and it's length as an agrument
  // and returns a number that states how many even numbers are in the array
  int arrayLength = sizeof(numbers)/sizeof(int);
  cout << "There are " << evenArrayElements(numbers, arrayLength) << " even numbers in the array.";
	return 0;
}
