#include <iostream>
using namespace std;

bool notIncluded(int *array, int length, int number) {
	for (int i = 0; i < length; i++) {
		if (array[i] == number) {
			return false;
		}
	}
	return true;
}
// Implement this function to create the union of a and b into the array result!
void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {
	for (int i = 0; i < l_a; i++) {
		result[i] = a[i];
	}
	int x = 0;
	for (int i = 0; i < l_b; i++) {
		if (notIncluded(result, l_a, b[i])) {
			result[l_a+x] = b[i];
			x++;
		}
	}
}

int main(int argc, char** argv) {
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int c[6];
	safeUnion(a,3,b,3,c,6);
	for (int i = 0; i<6; i++) cout <<c[i] << endl;

}
