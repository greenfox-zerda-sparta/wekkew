#include <iostream>
#include <math.h>
using namespace std;

struct Stack {
  int size;
  double* array = NULL;
  int stackSize;
};

void printStack(Stack& stack) {
  for (int i = 0; i < stack.size; i++) {
    cout << i+1 << " : " << stack.array[i] << endl;
  }
  cout << "size: " << stack.size << endl;
  cout << "stackSize: " << stack.stackSize << endl;
}

int calculateStackSize(unsigned int size) {
  int x = 0;
  int stackSize = pow(2, 4);
  while (size > stackSize*0.8) {
    stackSize = pow(2, 4+x);
    x++;
  }
  return stackSize;
}

Stack* costructStack(double* input, unsigned int size) {
  Stack* newStack = new Stack;
  int stackSize = calculateStackSize(size);
  newStack->size = size;
  newStack->stackSize = stackSize;
  newStack->array = new double[newStack->stackSize];
  for (unsigned int i = 0; i < size; i++) {
    newStack->array[i] = input[i];
  }
  return newStack;
}

void pushToStack(Stack& stack, double value) {
  stack.size++;
  if (stack.size > stack.stackSize*0.8) {
    int stackSize = calculateStackSize(stack.size);
    stack.stackSize = stackSize;
    double newArray = new double[stack.stackSize];
    for (unsigned int i = 0; i < stack.size; i++) {
      newArray[i] = stack.array[i];
    }
    stack.array[stack.size] = value;
    delete[] stack.array;
    stack.array = newArray;
  }
  else {
    stack.array[stack.size-1] = value;
    }
}

double popFromStack(Stack& stack) {
  stack.size--;
  return stack.array[stack.size];
}

int main() {
  double array[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
  Stack* myStack = costructStack(array, 18);
  printStack(*myStack);



  delete[] myStack->array;
  delete myStack;
	return 0;
}
