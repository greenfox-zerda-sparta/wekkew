#include "numberVector.h"

using namespace std;

int numberVector::getSum() {
  int sum = 0;
  for (int i = 0; i < storage.size(); i++) {
    sum += storage[i];
  }
  return sum;
}

void numberVector::addToVector(int number) {
  storage.push_back(number);
}
