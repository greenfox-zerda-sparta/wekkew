/*
 * Shape.cpp
 *
 *  Created on: 2016. nov. 9.
 *      Author: dixi
 */

#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Shape::Shape() {
  // TODO Auto-generated constructor stub
}

string* Shape::getName() {
  return new string("Generic Shape");
}


