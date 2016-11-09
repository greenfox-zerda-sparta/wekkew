#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Square::Square() {
	// TODO Auto-generated constructor stub

}

string* Square::getName() {
	return new string("Square");
}

Square::~Square() {
	// TODO Auto-generated destructor stub
}


