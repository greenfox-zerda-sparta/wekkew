#include <iostream>
#include "Triangle.h"

namespace std {

Triangle::Triangle(int lines) {
  this->lines = lines;
}

void Triangle::printTriangle() {
  for (int i = 1; i < lines+1; i++) {
   for (int j = 0; j < i; j++) {
     cout << "*";
   }
   cout << endl;
  }
}

Triangle::~Triangle() {
  // TODO Auto-generated destructor stub
}

} /* namespace std */
