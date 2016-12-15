#include <iostream>
#include <cstdlib>

using namespace std;

int reindeerAntlerCounter(int reindeerNumbers) {
  if (reindeerNumbers > 0) {
    if (reindeerNumbers % 2) {
      return 2 + reindeerAntlerCounter(reindeerNumbers - 1);
    }
    else {
      return 3 + reindeerAntlerCounter(reindeerNumbers - 1);
    }
  }
  return 0;
}

int main() {
  // We have reindeers standing in a line, numbered 1, 2, ... The odd reindeers
  // (1, 3, ..) have the normal 2 antlers. The even reindeers (2, 4, ..) we'll say
  // have 3 antlers, because they each have a raised a branch (how funny they are, arent they?). 
  //Recursively return the number of "antlers" in the reindeer line 1, 2, ... n (without loops or
  // multiplication).
  cout << reindeerAntlerCounter(4) << endl;

  system("pause");
  return 0;
}