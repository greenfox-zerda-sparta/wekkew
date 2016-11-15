#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "first-exercise.txt"
  // Write your name in it as a single line
  ofstream myFile;
  myFile.open("firstExcersice.txt");
  myFile << "Kristof Czetenyi\n";
  myFile.close();

  return 0;
}
