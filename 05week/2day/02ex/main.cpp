#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open a file called "second-exercise.txt"
  // Read the content of the file and print it to the terminal window
  ifstream myFile;
  myFile.open("secondExcersice.txt");
  string content;
  myFile >> content;
  myFile.close();
  cout << content;

  return 0;
}
