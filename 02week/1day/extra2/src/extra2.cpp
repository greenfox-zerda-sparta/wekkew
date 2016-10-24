#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	//prime numbers up to 2000
	int howmany = 0;
	int upto = 2000;
	for (int num = 0; num < upto; num++) {
		bool prime = true;
		for (int div = 2; div < num; div++) {
			if (num%div == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			cout << num << endl;
			howmany += 1;
		}
	}
	cout << "There are " << howmany << " prime numbers between 0 and " << upto << ".";
	return 0;
}
