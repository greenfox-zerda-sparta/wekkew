#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool copyFile(string originalPath, string copyPath) {
  ifstream myFile;
  bool succes = true;
  myFile.open(originalPath.c_str());
  if (!myFile.is_open()) {
    succes = false;
  }
  string line;
  while (myFile >> line) {
    ofstream copyFile;
    copyFile.open(copyPath.c_str());
    if (!copyFile.is_open()) {
      succes = false;
    }
    copyFile << line;
    copyFile.close();
  }
  myFile.close();
  if (succes) {
    return true;
  } else {
    return false;
  }

}

int main() {
  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful
  cout << copyFile("6thEx.txt", "8thEx.txt") << endl;
  return 0;
}
