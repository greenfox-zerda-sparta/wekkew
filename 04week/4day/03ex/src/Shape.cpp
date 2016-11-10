#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Shape::Shape() {
  mArea = 0;
}

string* Shape::getName() {
  return new string("Generic Shape");
}



