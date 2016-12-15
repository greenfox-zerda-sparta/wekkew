#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string removeAllLowercaseXFromAString(string word) {
  string newWord = "";
  if (word.length() > 0) {
    if (word[0] != 'x') {
      newWord = word[0];
    }
    word.erase(0, 1);
    return newWord += removeAllLowercaseXFromAString(word);
  } else {
    return "";
  }
}

int main() {
  // Given a string, compute recursively a new string where all the 'x' chars have been removed.
  string word1 = "ax";
  string word = "mxexrxrxyx xXxmxaxsx";
  cout << removeAllLowercaseXFromAString(word) << endl;
  
  system("pause");
  return 0;
}