#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

// Duplicate the Stack class from the previous exercise.
// Rewrite it so, that the push and pop methods don't throw integers.
// Define an enum for the two types of exceptions.
// Adapt the interpretException method to except an argument from that enum type.
// Adapt the main function so that the try and catch blocks except an exception of that enum type.

string interpretException(errors);

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
    cout << interpretException(enumError) << endl;
  }

  return 0;
}

string interpretException(errors error) {
  switch (error) {
    case OUT: {
      return "Out of memory";
    }
    case NOTHING: {
      return "Nothing on stack";
    }
    default :
      return "fuck it";
  }
}
