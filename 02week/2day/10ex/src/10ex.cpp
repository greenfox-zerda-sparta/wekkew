#include <iostream>
#include <string>

using namespace std;

int doubler(int x) {
	return x*2;
}

int main() {
  int j = 123;
  // create a function that doubles it's input
  // double j with it
  cout << doubler(j);
  return 0;
}
