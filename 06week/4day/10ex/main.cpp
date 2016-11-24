#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int howManyDivisorsHas(int number) {
  int returnValue = 0;
  for (int i = 1; i < number/2; i++) {
    if (number%i == 0) {
      returnValue++;
    }
  }
  return returnValue;
}

int main() {
	//find how much integer divisor 2400 has
	//create a vector of doubles, reserve place for the divisors of 2400
	//fill this places with random numbers from 0 to 2400
	//sort them in ascending order
  cout << howManyDivisorsHas(2400) << endl;
  vector<double> numbers(howManyDivisorsHas(2400));
  for (int i = 0; i < numbers.size(); i++) {
    numbers[i] = rand()%2400;
  }
  sort(numbers.begin(), numbers.end());
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " | ";
  }
  cout << endl;

  return 0;
}
