#include <iostream>
#include <string>

using namespace std;

int main() {
	long long i = 476586587657685643;
	// tell if it has 11 as a divisor
	if (i%11 == 0) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
	return 0;
}
