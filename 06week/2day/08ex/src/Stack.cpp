#include "Stack.h"

Stack::Stack() {
  this->array = new int[5];
  this->lastIndex = -1;
}

void Stack::pushOnStack(int value) {
  lastIndex++;
  if (lastIndex > 4) {
    throw 1;
  } else {
    array[lastIndex] = value;
  }
}

int Stack::popFromStack() {
  if (lastIndex < 0) {
    throw 2;
  }
  lastIndex--;
  return array[lastIndex+1];
}

Stack::~Stack() {
  delete[] this->array;
}
