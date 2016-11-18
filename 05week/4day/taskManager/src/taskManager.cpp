#include "taskManager.h"
#include <fstream>
#include <string>
#include "util.h"
#include "task.h"
#include <iostream>

using namespace std;

taskManager::taskManager() {
  ifstream taskList;
  taskList.open("taskList.txt");
  if (!taskList.is_open()) {
    ofstream newTaskList;
    newTaskList.open("taskList.txt");
    newTaskList.close();
    ifstream taskList;
    taskList.open("taskList.txt");
  }
  string line;
  taskCounter = countTasks("taskList.txt");
  task** tasks = new task*[taskCounter];
  int vecorIndex = 0;
  while (getline(taskList, line)) {
    char status = line[line.length()-1];
    string taskName = line.erase(line.length()-1);
    task* newTask = new task(taskName, vecorIndex);
    if (status == '1') {
      newTask->complete = true;
    } else {
      newTask->complete = false;
    }
    tasks[vecorIndex] = newTask;
    vecorIndex++;
  }
  delete[] taskVector;
  taskVector = tasks;
}

void taskManager::addTask(string taskName) {
  task* newTask = new task(taskName, taskCounter);
  task** newVector = new task*[taskCounter+1];
  for (int i = 0; i < taskCounter; i++) {
    newVector[i] = taskVector[i];
  }
  newVector[taskCounter] = newTask;
  delete[] taskVector;
  taskVector = newVector;
  taskCounter++;
  listAllTasks();
}

void taskManager::listAllTasks() {
  if (taskCounter == 0) {
    printFile("nothingToDoHere.txt");
    return;
  }
  for (int i = 0; i < taskCounter; i++) {
  cout << this->taskVector[i]->id +1 << " - ";
  this->taskVector[i]->complete ? cout <<"[x] " : cout << "[ ] ";
  cout << this->taskVector[i]->name << endl;
  }
}

void taskManager::listUncompletedTasks() {
  if (taskCounter == 0) {
    printFile("nothingToDoHere.txt");
    return;
  }
  for (int i = 0; i < taskCounter; i++) {
    if (!taskVector[i]->complete) {
      cout << this->taskVector[i]->id +1 << " - ";
      this->taskVector[i]->complete ? cout <<"[x] " : cout << "[ ] ";
      cout << this->taskVector[i]->name << endl;
    }
  }
}

void taskManager::removeTask(int serial) {
  if (serial > taskCounter) {
    printError(1);
    return;
  }
  int index = serial - 1;

  task** newVector = new task*[taskCounter-1];
  for (int i = 0; i < index; i++) {
    newVector[i] = this->taskVector[i];
  }
  taskCounter--;
  for (int i = index; i < taskCounter; i ++) {
    newVector[i] = this->taskVector[i+1];
  }
  delete[] this->taskVector;
  this->taskVector = newVector;
  listAllTasks();
}

void taskManager::completeTask(int serial) {
  if (serial > taskCounter) {
    printError(1);
    return;
  }
  int index = serial-1;
  this->taskVector[index]->complete = true;
  listAllTasks();
}

void taskManager::completeAllTasks() {
  for (int i = 0; i < taskCounter; i++) {
    taskVector[i]->complete = true;
  }
}

void taskManager::removeCompleteTasks() {
  for (int i = 0; i < taskCounter; i++){
    if (taskVector[i]->complete) {
      int serial = i+1;
      removeTask(serial);
    }
  }
}

void taskManager::removeAll() {
  while (taskCounter > 0) {
    this->removeTask(1);
  }
}

taskManager::~taskManager() {
  ofstream myFile;
  myFile.open("taskList.txt");
  for (int i = 0; i < taskCounter; i++) {
    string toFile = taskVector[i]->name;
    toFile += taskVector[i]->complete ? "1" : "0" ;
    toFile += "\n";
    myFile << toFile;
  }
  myFile.close();
  delete[] taskVector;
}
