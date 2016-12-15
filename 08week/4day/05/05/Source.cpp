#include <iostream>
#include <cstdlib>

using namespace std;

int RudolfEarComputer(int howManyRudolf) {
  if (howManyRudolf > 0) {
    return 2 + RudolfEarComputer(howManyRudolf - 1);
  } 
  return 0;
}

int main() {
  // We have a number of reindeers and each Rudolf has two big floppy ears.
  // We want to compute the total number of ears across all the reindeers
  // recursively (without loops or multiplication).
  cout << RudolfEarComputer(8) << endl;

  system("pause");
  return 0;
}