#include <iostream>
using namespace std;

struct Stack {
  int size;
  double* array = NULL;
};

void printStack(Stack& stack) {
  for (int i = 0; i < stack.size; i++) {
    cout << i+1 << " : " << stack.array[i] << endl;
  }
  cout << "stack.size: " << stack.size << endl;
}

Stack* stackCostruct(double* input, int size) {
  Stack* newStack = new Stack;
  newStack->size = size;
  newStack->array = new double[size];
  for (int i = 0; i < size; i++) {
    newStack->array[i] = input[i];
  }
  return newStack;
}

void pushStack(Stack& stack, double value) {
  double* newArray = new double[stack.size+1];
  for (int i = 0; i < stack.size; i++) {
    newArray[i] = stack.array[i];
  }
  newArray[stack.size] = value;
  delete stack.array;
  stack.array = newArray;
  stack.size++;
}

double popStack(Stack& stack) {
  double returnValue = stack.array[stack.size-1];
  double* newArray = new double[stack.size-1];
  for (int i = 0; i < stack.size-1; i++) {
    newArray[i] = stack.array[i];
  }
  delete stack.array;
  stack.array = newArray;
  stack.size--;
  return returnValue;
}

bool isEmptyStack(Stack& stack) {
  return stack.size > 0 ? false : true;
}

int main() {
  double array[3] = {1, 2, 3};
  Stack* myFirstStack = stackCostruct(array, 3);
  printStack(*myFirstStack);
  pushStack(*myFirstStack, 5);
  printStack(*myFirstStack);
  cout << popStack(*myFirstStack)<< "POP" << endl;
  cout << popStack(*myFirstStack)<< "POP" << endl;
  cout << popStack(*myFirstStack)<< "POP" << endl;
  cout << popStack(*myFirstStack)<< "POP" << endl;
  cout << isEmptyStack(*myFirstStack) << endl;
  printStack(*myFirstStack);

	return 0;
}
