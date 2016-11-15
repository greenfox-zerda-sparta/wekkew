#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream myFile;
  myFile.open("11thEx.txt");
  int lineCount = 0;
  string line;
  while (getline(myFile, line)) {
    lineCount++;
  }

  myFile.close();
  ofstream newFile;
  newFile.open("new11thEx.txt");
  for (int i = 0; i < lineCount; i++) {
    myFile.open("11thEx.txt");
    for (int j = lineCount-i; j > 0; j--) {
      getline(myFile, line);
    }
    newFile << line << "\n";
    myFile.close();
  }
  newFile.close();

  return 0;
}
