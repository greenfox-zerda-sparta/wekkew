#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int digitSummer(unsigned int n) {
  if (n > 0) {
    return (n % 10) + digitSummer(n / 10);
  }
  return 0;
}

int main() {
  // Given a non-negative int n,
  // return the sum of its digits recursively (no loops).
  // Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
  // while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
  cout << digitSummer(123) << endl;

  system("pause");
  return 0;
}