#include <iostream>
#include <string>
#include <cmath>
#include "Circle.h"

using namespace std;


Circle::Circle(double radius) {
  this->radius = radius;
}

double Circle::getCircumference() {
  return this->radius*2*pi;
}

double Circle::getArea() {
  return pi*pow(this->radius, 2);
}

