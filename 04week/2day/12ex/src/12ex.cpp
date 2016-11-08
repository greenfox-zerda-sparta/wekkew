#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main() {
    // Create a triangle class that takes a length parameter and prints a triangle like this:
    //       *
    //      ***
    //     *****
    //    *******
    //   *********
    //  ***********
    //
    // It should take a number as parameter that describes how many lines the triangle has

  Tree myTree(5);
  myTree.printTree();
  return 0;
}
