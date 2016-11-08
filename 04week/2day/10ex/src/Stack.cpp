/*
 * Stack.cpp
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */
#include <iostream>
#include "Stack.h"

namespace std {

Stack::Stack() {
  // TODO Auto-generated constructor stub
}

void Stack::push(double element) {
  if (length > this->size*0.8) {
    this->size *= 2;
    double* newArray = new double[this->size];
    for (unsigned int i = 0; i < length; i++) {
      newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
  }
  length++;
  array[length-1] = element;
}

int Stack::stackSize() {
  return length;
}

double Stack::pop() {
  length--;
  return array[length];
}

Stack::~Stack() {
  // TODO Auto-generated destructor stub
}

} /* namespace std */
