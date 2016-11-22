#ifndef STACK_H
#define STACK_H

enum errors {OUT, NOTHING, FUCK};

class Stack {
  public:
    Stack();
    void pushOnStack(int);
    void popFromStack();
    virtual ~Stack();
  private:

    int* array;
    int lastIndex;
};

#endif // STACK_H
