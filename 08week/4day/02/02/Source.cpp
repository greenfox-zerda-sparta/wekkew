#include <iostream>
#include <cstdlib>

using namespace std;

int addToN(int n) {
  while (n > 0) {
    return n + addToN(n - 1);
  }
  return -1;
}

int main() {
  cout << addToN(6) << endl;

  system("pause");
  return 0;
}