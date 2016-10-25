#include <iostream>
#include <string>

using namespace std;

int main() {
  int h[] = {3, 4, 5, 6, 7};
	// print the sum of all numbers in h
  int arrayLength = sizeof(h)/sizeof(int);
  int answare;

  for (int i = 0; i < arrayLength; i++) {
	  answare += h[i];
  }
  cout << answare;
  return 0;
}
