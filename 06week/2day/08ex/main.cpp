#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.

// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

string interpretException(int);

int main() {
  try {
    Stack alma;
    cout << alma.popFromStack() << endl;
    alma.pushOnStack(0);
    alma.pushOnStack(1);
    alma.pushOnStack(2);
    alma.pushOnStack(3);
    alma.pushOnStack(4);
    alma.pushOnStack(5);
    cout << alma.popFromStack() << endl;
  } catch (int intError) {
    cout << interpretException(intError) << endl;
  }

  return 0;
}

string interpretException(int error) {
  switch (error) {
    case 1: {
      return "Out of memory";
    }
    case 2: {
      return "Nothing on stack";
    }
    default :
      return "fuck it";
  }
}
