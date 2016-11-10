#include <iostream>
#include <string>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

int main() {
  Shape* shape = new Shape();
  Triangle* triangle = new Triangle(4,5);
  Square* square = new Square(3);
  Shape* a;
  cout << "I am a...  " << *shape->getName() << endl;
  cout << "I am a...  " << *triangle->getName() << endl;
  cout << "I am a...  " << *square->getName() << endl;

  a = square;
  cout << "I am a...  " << *a->getName() << endl;

  a = triangle;
  cout << "I am a...  " << *a->getName() << endl;
  return 0;
}


// First, move the previous code to new hpp and cpp files for each class.
// Include them into this file.
// Make sure they include each other when needed.
// Make sure the code below still works.

// Add a variable to the Shape class. Make it "protected".
//    This should be called mArea.
// Create a function that calculates the areas of the shape.
// Update the shapes Triangle and Square to have variables that represent their dimensions,
//   that you will need to calculate the area. One would be width, the other height.
// Implement getter and setter functions for them.
// Make sure to call the function that calculates the area and stores it in mArea,
//   in the setter functions.
// Create a constructor that takes the height and width as it's parameters.
// Create a destructor, that destructs the objects.
//
// Write code into the main function that uses these.
// Make sure it demonstrates how the class works by printing out the results.

