#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string addStartToEveryCharacter(string word) {
  string newWord = "";
  if (word.length() > 0) {
    if (word.length() > 1) {
      newWord += word[0];
      newWord += '*';
    } else {
      newWord += word[0];
    }
    word.erase(0, 1);
    return newWord += addStartToEveryCharacter(word);
  }
  else {
    return "";
  }
}

int main() {
  // Given a string, compute recursively a new string where all the
  // adjacent chars are now separated by a "*".
  
  cout << addStartToEveryCharacter("alma") << endl;;

  system("pause");
  return 0;
}