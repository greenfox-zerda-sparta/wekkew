#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string path, string input) {
  ofstream myFile;
  myFile.open(path.c_str());
  myFile << input;
  myFile.close();
}


int main() {
  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter

  writeFile("7thEx.txt", "fucking lunch break");
  return 0;
}
