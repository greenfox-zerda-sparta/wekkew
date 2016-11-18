#ifndef TASKMANAGER_H
#define TASKMANAGER_H

using namespace std;

class taskManager {
  public:
    taskManager();

    void addTask(string);           //-a
    void listAllTasks();            //-l
    void listUncompletedTasks();    //-lu
    void removeTask(int);           //-r
    void removeCompleteTasks();     //-rc
    void removeAll();               //-ra
    void completeTask(int);         //-c
    void completeAllTasks();        //-ca

    virtual ~taskManager();
  protected:
    int taskCounter;
    task** taskVector;
};

#endif // TASKMANAGER_H
