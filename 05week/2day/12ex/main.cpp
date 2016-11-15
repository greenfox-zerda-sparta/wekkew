#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(int step) {
  ifstream myFile;
  myFile.open("12thEx.txt");
  string line;
  ofstream newFile;
  newFile.open("new12thEx.txt");
  while (getline(myFile, line)) {
    string newline;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == ' ') {
        newline += ' ';
      }
      newline += line[i]+step;
    }
    newFile << newline << "\n";
  }
  myFile.close();
  newFile.close();
}


int main() {
  encryptFile(-1);

  return 0;
}
