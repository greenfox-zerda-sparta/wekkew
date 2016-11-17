#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "task.h"

using namespace std;

class taskManager {
  public:
    taskManager();

    void addTask(string);
    void listAllTasks();
    void removeTask(int);
    void completeTask(int);

    virtual ~taskManager();
  protected:
    int taskCounter;
    task** taskVector;
};

#endif // TASKMANAGER_H
