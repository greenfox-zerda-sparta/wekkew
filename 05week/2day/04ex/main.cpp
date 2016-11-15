#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open a file called "fourth-exercise.txt"
  // Print all of its lines to the terminal window
  ifstream myFile;
  myFile.open("fourthExcersice.txt");
  string content;
  while (myFile >> content) {
    cout << content << endl;
  }
  myFile.close();

  return 0;
}
