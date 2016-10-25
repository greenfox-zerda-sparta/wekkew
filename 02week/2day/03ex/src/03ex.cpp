#include <iostream>
#include <string>

using namespace std;

int main() {
	int d[] = {6, 5, 4, 3, 2, 1};
	// print all the elements of the array

	int arrayLength = sizeof(d)/sizeof(int);
	for (int i = 0; i < arrayLength; i++) {
		cout << d[i] << endl;
	}


  return 0;
}
