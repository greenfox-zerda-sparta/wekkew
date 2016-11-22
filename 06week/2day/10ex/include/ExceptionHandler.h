#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <string>
#include "Stack.h"

using namespace std;

class ExceptionHandler {
  public:
    ExceptionHandler(errors);
    string toString();
    virtual ~ExceptionHandler();
  private:
    errors enumError;
    int intError;
};

#endif // EXCEPTIONHANDLER_H
