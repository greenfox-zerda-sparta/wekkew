#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
  // Create a `Stack` class that stores elements
  // It should have a `size` method that returns number of elements it has
  // It should have a `push` method that adds an element to the stack
  // It should have a `pop` method that returns the last element form the stack and also deletes it from it
  Stack myStack;
  myStack.push(0);
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  myStack.push(4);
  cout << myStack.stackSize() << endl;
  cout << myStack.pop() << endl;
  cout << myStack.stackSize() << endl;

  return 0;
}
