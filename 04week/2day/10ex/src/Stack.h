/*
 * Stack.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef STACK_H_
#define STACK_H_

namespace std {

class Stack {
public:
  Stack();
  int stackSize();
  void push(double element);
  double pop();
  virtual ~Stack();
private:
  double* array = new double[2];
  unsigned int size = 2;
  unsigned int length = 0;
};

} /* namespace std */

#endif /* STACK_H_ */
