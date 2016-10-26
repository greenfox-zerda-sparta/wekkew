#include <iostream>
using namespace std;
void change(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// Implement this function to sort the array in an ascending order.
void sortAscending(int *array, int length) {
	bool hasChange = false;
	for (int i = 0; i < length - 1; i++) {
		if (array[i] > array[i+1]) {
			change(array, i, i+1);
			hasChange = true;
		}
	}
	if (hasChange) {
		sortAscending(array, length);
	}
}

// Implement this function to sort the array in a descending order.
void sortDescending(int *array, int length) {
	bool hasChange = false;
	for (int i = 0; i < length - 1; i++) {
		if (array[i] < array[i+1]) {
			change(array, i, i+1);
			hasChange = true;
		}
	}
	if (hasChange) {
		sortDescending(array, length);
	}
}

void printArray(int *array, int length) {
	cout << "{";
	for(int i=0; i<length; i++){
		cout << array[i];
		if(i<length-1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

int main(int argc, char** argv){
	int example[13] = {34, 56, 26, 84, 29, 3875, 43, 96, 4759, 979, 92, 56, 1987};
	printArray(example, 13);
	sortAscending(example, 13);
	printArray(example, 13);
	sortDescending(example, 13);
	printArray(example, 13);

	return 0;
}
