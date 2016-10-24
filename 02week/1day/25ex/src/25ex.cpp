#include <iostream>
#include <string>

using namespace std;

int main() {
	// print the even numbers till 20
	for (int i = 0; i <= 20; i++) {
		if (i%2 == 0) { // 0 included because 0 divided by 2 gives 0
			cout << i << endl;
		}
	}
	return 0;
}
