#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

Square::Square() {}

string* Square::getName() {
    return new string("square");
}

Square::~Square() {}
