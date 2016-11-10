#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"

Shape::Shape() {}

string* Shape::getName() {
	return new string("Generic Shape");
}

Shape::~Shape() {}
