#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void changeAllLowerXCharacterToLowerYCharacterInAString(string& word, int stringLength) {
  stringLength--;
  if (stringLength > 0) {
    if (word[stringLength] == 'x') {
      word[stringLength] = 'y';
    }
    changeAllLowerXCharacterToLowerYCharacterInAString(word, stringLength);
  }
}

int main() {
  // Given a string, compute recursively (no loops) a new string where all the
  // lowercase 'x' chars have been changed to 'y' chars.

  string word = "merrx Xmas";
  cout << word << endl;
  changeAllLowerXCharacterToLowerYCharacterInAString(word, word.length());
  cout << "change" << endl << word << endl;
  system("pause");
  return 0;
}