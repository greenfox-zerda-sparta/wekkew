#include <iostream>
#include <string>
#include "Stack.h"
#include "ExceptionHandler.h"
using namespace std;

// Duplicate the Stack class from the previous exercies.
// Create a class for Your exception.
// The class should have two private fields:
// 1.) A field from Your enum type to represent the kind of error.
// 2.) A field of type: int. So You can give back the element or the index which caused the problems.
// Set all the fields in the constructor only.
// Create get... methods for both variables.
// Create an std::string toString() method, which gives back a comprehensive error message.
//
// Demonstrate how this works in the main function. Print the error messages from the main function.


int main() {
  try {
    Stack alma;
    alma.popFromStack();
    alma.pushOnStack(0);
    alma.pushOnStack(1);
    alma.pushOnStack(2);
    alma.pushOnStack(3);
    alma.pushOnStack(4);
    alma.pushOnStack(5);
    alma.popFromStack();
  } catch (errors enumError) {
    ExceptionHandler apple(enumError);
    cout << apple.toString() << endl;
  }

  return 0;
}

