#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int h1 = 350;
	int h2 = 200;
	// tell if the double of h2 is bigger than h1
	bool a;
	if (h2*2 > h1) {
		a = true;
	}
	else {
		a = false;
	}
	cout << a;
	return 0;
}
