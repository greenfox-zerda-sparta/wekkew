#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main() {
  ifstream myFile;
  myFile.open("9thEx.txt");
  string word;
  ofstream newFile;
  newFile.open("new9thEx.txt");
  bool space = true;
  while (myFile >> word) {
    for (int i = 0; i < word.length(); i+=2) {
      newFile << word[i];
      if (word[i] == '.') {
        newFile << "\n";
        space = false;
      }
    }
    if (space) {
      newFile << ' ';
    }
    space = true;
  }
  myFile.close();
  newFile.close();
  return 0;
}
