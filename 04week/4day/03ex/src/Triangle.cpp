#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Triangle::Triangle(double height, double width) {
	this->heigth = height;
	this->width = width;
}

string* Triangle::getName() {
	return new string("Triangle");
}

void Triangle::calculateArea() {
  mArea = heigth*width/2;
}

double Triangle::getArea() {
  return mArea;
}




