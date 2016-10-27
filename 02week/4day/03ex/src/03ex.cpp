#include <iostream>

using namespace std;

void swapPointer(int* a, int* b) {
	int temporary = *a;
	*a = *b;
	*b = temporary;
	cout << a << ":" << *a << endl;
	cout << b << ":" << *b << endl;
}

int main() {
  int first = 12;
  int second = 54;
  // Write a function that takes two int pointers and swaps the values where the pointers point
  int* firstPointer = &first;
  int* secondPointer = &second;
  swapPointer(firstPointer, secondPointer);

  return 0;
}
