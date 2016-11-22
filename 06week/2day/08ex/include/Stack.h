#ifndef STACK_H
#define STACK_H


class Stack {
  public:
    Stack();
    void pushOnStack(int);
    int popFromStack();
    virtual ~Stack();
  private:
    int* array;
    int lastIndex;
};

#endif // STACK_H
