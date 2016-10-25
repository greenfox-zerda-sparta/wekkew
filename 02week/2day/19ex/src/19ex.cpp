#include <iostream>
using namespace std;

bool isPrime(int number) {
		for (int index = 2; index < number; index++) {
		if (number%index == 0) {
			return false;
		}
	}
	return true;
}

int main(){
  int number = 121;
  // create a function that decides if a number is a prime number.
  // It should take a number as an argument and return true if it is prime and
  // false otherwise.
  cout << number << " is a prime number: " << isPrime(number);
	return 0;
}
