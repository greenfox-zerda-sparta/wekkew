#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Triangle::Triangle() {
	// TODO Auto-generated constructor stub
}

string* Triangle::getName() {
	return new string("Triangle");
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}


