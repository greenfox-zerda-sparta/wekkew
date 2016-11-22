#include "Stack.h"


Stack::Stack() {
  this->array = new int[5];
  this->lastIndex = -1;
}

void Stack::pushOnStack(int value) {
  lastIndex++;
  if (lastIndex > 4) {
    throw OUT;
  } else {
    array[lastIndex] = value;
  }
}

void Stack::popFromStack() {
  if (lastIndex < 0) {
    throw NOTHING;
  }
  lastIndex--;
}

Stack::~Stack() {
  delete[] this->array;
}
