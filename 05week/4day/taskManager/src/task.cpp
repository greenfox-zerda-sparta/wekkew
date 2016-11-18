#include "task.h"
#include <iostream>

task::task(string taskName, int taskID) {
  this->name = taskName;
  this->id = taskID;
  this->complete = false;
}

task::~task() {
}
