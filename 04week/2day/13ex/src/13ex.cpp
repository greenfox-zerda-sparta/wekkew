#include <iostream>
#include <string>
#include "Diamond.h"

using namespace std;

int main() {
    // Create a triangle class that takes a length parameter and prints a diamond like this:
    //       *
    //      ***
    //     *****
    //    *******
    //   *********
    //  ***********
    //   *********
    //    *******
    //     *****
    //      ***
    //       *
    //
    // It should take a number as parameter that describes how many lines the diamond has
 Diamond myDiamond(5);
 myDiamond.printDiamond();

  return 0;
}
