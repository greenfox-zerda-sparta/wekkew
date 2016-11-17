#include "util.h"
#include "taskManager.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

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
    cerr << "no such file" << endl;
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
    cerr << "Arguments must begins with \"-\" character!" << endl;
    return;
  } else {
    taskManager greenfox;
    switch (firstArgument[1]) {
      case 'l': {
        greenfox.listAllTasks();
        break;
      }
      case 'a': {
        if (!(argc > 2)) {
          cerr << "Enter a taskname please!" << endl;
          return;
        }
        string taskName = argv[2];
        greenfox.addTask(taskName);
        break;
      }
      case 'r': {
        if (!(argc > 2)) {
          cerr << "Enter a task serial number please!" << endl;
          return;
        }
        int serie = atoi(argv[2]);
        greenfox.removeTask(serie);
        break;
      }
      case 'c': {
        if (!(argc > 2)) {
          cerr << "Enter a task serial number please!" << endl;
          return;
        }
        int serie = atoi(argv[2]);
        greenfox.completeTask(serie);
        break;
      }
      default:
        cout << "Choose one from the given possibilities" << endl;
    }
  }
}
