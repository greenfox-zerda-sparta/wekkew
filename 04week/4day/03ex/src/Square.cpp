#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Square::Square(double heigth) {
	this->heigth= heigth;
}

string* Square::getName() {
	return new  string("Square");
}

void Square::calculateArea() {
  mArea = heigth*heigth;
}

double Square::getArea() {
  return mArea;
}

