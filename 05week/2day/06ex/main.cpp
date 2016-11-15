#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readFile(string path) {
  ifstream myFile;
  myFile.open(path.c_str());
  string fileContent;
  string line;
  while (myFile >> line) {
    fileContent = fileContent + line + "\n";
  }
  myFile.close();
  return fileContent;
}

int main() {
  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter
  cout << readFile("6thExcersice.txt") << endl;

  return 0;
}
