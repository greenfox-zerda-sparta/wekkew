#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream myFile;
  myFile.open("10thEx.txt");
  string line;
  ofstream newFile;
  newFile.open("new10thEx.txt");
  while (getline(myFile, line)) {
    int length = line.length();
    string temp;
    for (int i = 0; i < length; i++) {
      temp += line[length-1-i];
    }
    newFile << temp << "\n";
  }
  myFile.close();
  newFile.close();
  return 0;
}
