#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

// First, move the previous code to new hpp and cpp files for each class.
//CHECK
// Include them into this file.
//CHECK
// Make sure they include each other when needed.
//CHECK
// Make sure the code below still works.


int main() {
	Shape* shape = new Shape();
	Triangle* triangle = new Triangle();
	Square* square = new Square();
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
