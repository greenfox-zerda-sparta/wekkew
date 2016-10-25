#include <iostream>
#include <string>

using namespace std;

int factorFactory(int i) {
	int factorial = 1;
	while (i > 1) {
		factorial = factorial * i;
		i -= 1;
	}
	return factorial;
}

int main() {
  // create a function that returns it's input factorial
	cout << factorFactory(8);
  return 0;
}
