#include "ExceptionHandler.h"

ExceptionHandler::ExceptionHandler(errors enumError) {
  this->enumError = enumError;
  this->intError = enumError;
}

string ExceptionHandler::toString() {
  switch (this->enumError) {
    case OUT: {
      return "Out of memory";
    }
    case NOTHING: {
      return "Nothing on stack";
    }
    default :
      return "fuck it";
  }
}

ExceptionHandler::~ExceptionHandler()
{
  //dtor
}
