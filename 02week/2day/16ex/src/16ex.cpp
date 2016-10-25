#include <iostream>
using namespace std;


void printA(int array[][3], int matrix) {
	cout << "A" << endl;
		for (int i = 0; i < matrix; i++) {
			for (int j = 0; j < matrix; j++) {
				cout << array[i][j];
			}
			cout << endl;
		}
}

void printB(int array[][3], int matrix) {
	cout << "B" << endl;
	for (int i = 0; i < matrix; i++) {
		for (int j = 0; j < matrix; j++) {
			cout << array[j][i];
		}
		cout  << endl;
	}
}

void printC(int array[][3], int matrix) {
	cout << "C" << endl;
		for (int i = 0; i < matrix; i++) {
				for (int j = 0; j < matrix; j++) {
					cout << array[i][j] << "|";
				}
		}
}

void printD(int array[][3], int matrix) {
	cout << endl << "D" << endl;
		for (int i = 0; i < matrix; i++) {
				for (int j = 0; j < matrix; j++) {
					cout << array[i][j] << endl;
				}
		}
}

int main(){
	int m[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
	//This is an array of arrays. Print it out as a 3x3 matrix. Using each inner array as
	//a.) a row
	//b.) a column
	//c.) all in one line separated by the character '|'
	//d.) all in one column
	printA(m, 3);
	printB(m, 3);
	printC(m, 3);
	printD(m, 3);
	return 0;
}
