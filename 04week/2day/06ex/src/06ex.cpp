#include <iostream>
#include <string>
#include <cmath>
#include "Circle.h"

using namespace std;



int main() {
  // Create a `Circle` class that takes it's radius as constructor parameter
  // It should have a `get_circumference` method that returns it's circumference
  // It should have a `get_area` method that returns it's area
  Circle myCircle(5);
  cout << myCircle.getArea() << endl;
  cout << myCircle.getCircumference();

  return 0;
}
