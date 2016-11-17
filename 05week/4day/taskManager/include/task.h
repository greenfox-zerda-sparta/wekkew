#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class task {
  public:
    task(string taskName, int taskID);
    virtual ~task();

  protected:

  public:
    int id;
    string name;
    bool complete;
};

#endif // TASK_H
