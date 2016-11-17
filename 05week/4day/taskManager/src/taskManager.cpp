#include "taskManager.h"
#include <fstream>
#include <string>
#include "task.h"
#include "util.h"
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

void taskManager::removeTask(int serial) {
  if (serial > taskCounter) {
    cout << "Serial is out of bound" << endl;
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
}

void taskManager::completeTask(int serial) {
  if (serial > taskCounter) {
    cout << "Serial is out of bound" << endl;
    return;
  }
  int index = serial-1;
  this->taskVector[index]->complete = true;
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
