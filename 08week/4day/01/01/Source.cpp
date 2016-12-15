#include <iostream>
#include <cstdlib>

using namespace std;

void countDown(int n) {
  if (n < 0) {
    return;
  }
  cout << n << endl;
  countDown(n - 1);
}

int main() {
  countDown(10);

  system("pause");
  return 0;
}