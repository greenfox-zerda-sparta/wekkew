#include <iostream>
#include "Pop.h"


using namespace std;

int main() {
  Pop hello("hello", "adele");
  hello.rate(4);
  cout << hello.getEverything() << endl;

  return 0;
}
