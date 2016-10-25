#include <iostream>
#include <string>

using namespace std;

int main() {
	int f[] = {3, 4, 5, 6, 7};
	// Please double all the elements, than print all of them
	int arrayLength = sizeof(f)/sizeof(int);
	for (int i = 0; i < arrayLength; i++) {
		f[i] *= 2;
		cout << f[i] << endl;
	}

  return 0;
}
