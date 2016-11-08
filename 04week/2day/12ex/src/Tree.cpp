/*
 * Tree.cpp
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */
#include <iostream>
#include "Tree.h"

namespace std {

Tree::Tree(int trenches) {
  this->trenches = trenches;
}

void Tree::printTree() {
  for (int i = 0; i < trenches+1; i++) {
    for (int j = trenches-i; j >= 0; j--) {
      cout << " ";
    }
    for (int k = 1; k < i*2; k++) {
      cout << "*";
    }
    cout << endl;
  }
}

Tree::~Tree() {
  // TODO Auto-generated destructor stub
}

} /* namespace std */
