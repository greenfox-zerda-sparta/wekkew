#include "util.h"
#include "taskManager.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void printError(int index) {
  ifstream errorFile;
  errorFile.open("error.txt");
  string line;
  for (int i = 0; i < index; i++) {
    getline(errorFile, line);
  }
  cerr << line << endl;
}

int countTasks(string path) {
  ifstream myFile;
  myFile.open(path.c_str());
  string line;
  int counter = 0;
  while (getline(myFile, line)) {
    counter++;
  }
  return counter;
}

void printFile(string path) {
  ifstream myFile;
  myFile.open(path.c_str());
  if (!myFile.is_open()) {
    printError(2);
    return;
  }
  string line;
  while (getline(myFile, line)) {
    cout << line << endl;
  }
  myFile.close();
}

void checkArguments(int argc, char** argv) {
  if (argc == 1) {
    printFile("usageInformation.txt");
    return;
  }
  string firstArgument = argv[1];
  if (firstArgument[0] != '-') {
    printError(3);
    return;
  } else {
    taskManager greenfox;
    switch (firstArgument[1]) {
      case 'l': {
        if (firstArgument[2] == 'u') {
          greenfox.listUncompletedTasks();
          break;
        }
        greenfox.listAllTasks();
        break;
      }
      case 'a': {
        if (!(argc > 2)) {
          printError(4);
          break;
        }
        string taskName = argv[2];
        greenfox.addTask(taskName);
        break;
      }
      case 'r': {
        if (firstArgument[2] == 'c') {
          greenfox.removeCompleteTasks();
          break;
        }
        if (firstArgument[2] == 'a') {
          greenfox.removeAll();
          break;
        }
        if (!(argc > 2)) {
          printError(5);
          return;
        }
        int serie = atoi(argv[2]);
        greenfox.removeTask(serie);
        break;
      }
      case 'c': {
        if (firstArgument[2] == 'a') {
          greenfox.completeAllTasks();
          break;
        }
        if (!(argc > 2)) {
          printError(5);
          return;
        }
        int serie = atoi(argv[2]);
        greenfox.completeTask(serie);
        break;
      }
      default:
        printError(6);
    }
  }
}
