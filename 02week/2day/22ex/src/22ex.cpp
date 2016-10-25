#include <iostream>
using namespace std;

string includes(int array[10], int number) {
	for (int index = 0; index < 10; index++) {
		if (array[index] == number) {
			return "Included!";
		}
	}
	return "Not included!";
}

int firstIndexOf(int array[10], int number) {
	if (includes(array, number) == "Included!") {
		for (int index = 0; index < 10; index++) {
				if (array[index] == number) {
					return index;
				}
			}
	} else {
		return -1;
	}
}

int lastIndexOf(int array[10], int number) {
	if (includes(array, number) == "Included!") {
		for (int index = 9; index >=  0; index--) {
			if (array[index] == number) {
				return index;
			}
		}
	}
	else {
		return -1;
	}
}

//Create a function to tell You whether a certain number is part of a 10 long array of integers.
//Create an other function to give You the first index of a given integer in an array of integers.
//Create an other functions to give You the index of the last occurrence of the given integer in
//the array.If the array does not include the given integer this function should return -1.
//Do not duplicate functionality, use the functions You've created earlier instead of duplicating.
//Create 5 arrays, each 10 long filled with integers.
//Find the first and last occurrences of the integer: 14. And Print them out. If the array does not
//include the integer You should say so in words.
//The names of the functions should be "includes", "firstIndexOf", "lastIndexOf"
//Decide what should the function return. Void? Bool? Int? Float? Char?

int main(int argc, char** argv){

	int firstA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};
	int secA[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int thirdA[10] = {2, 3, 3, 4, 2, 3, 2, 3, 2, 3};
	cout << includes(firstA, 10) << endl;
	cout << firstIndexOf(firstA, 2) << endl;
	cout << lastIndexOf(thirdA, 3);

	return 0;
}
