#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the index is out of bounds, throw an exception.
// If the character is not in the string throw a different exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.

vector<string> stringSeparator(string, char);

int main() {
  try {
    vector<string> result = stringSeparator("We have a nice day, haven't we?", ' ');
    int length = result.size();
    for (int i = 0; i < length; i++){
      cout << result[i] << " ";
    }
    cout << endl;
  } catch (const char* error) {
    cout << error << endl;
  }
  return 0;
}

vector<string> stringSeparator(string originalString, char separator) {
  int charCounter = 1;
  for (int i = 0; i < originalString.length(); i++) {
    if (originalString[i] == separator) {
      charCounter++;
    }
  }
  if (charCounter == 1) {
    throw "no such character in the given string";
  }
  vector<string> returnVector;
  string tempWord;
  for (int i = 0; i <= originalString.length(); i++) {
    if (originalString[i] == separator || i == originalString.length()) {
      i++;
      returnVector.push_back(tempWord);
      cout << tempWord << endl;
      tempWord = "";
    }
    tempWord += originalString[i];
  }
  return returnVector;
}
