#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int power(int base, int n) {
  if (n > 0) {
    return base * power(base, n - 1);
  }
  return 1;
}

int main() {
  // Given base and n that are both 1 or more, compute recursively (no loops)
  // the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
  cout << power(4, 4) << endl;

  system("pause");
  return 0;
}