#include "WordToolbox.h"
#include <string>
#include <algorithm>

using namespace std;

WordToolbox::WordToolbox(string stringHeld) {
  this->stringHeld = stringHeld;
}

void WordToolbox::setString(string word) {
  this->stringHeld = word;
}

string WordToolbox::getString() {
  return stringHeld;
}

string WordToolbox::removeSpaces(string stringToCheck) {
  string newString;
  for (int i = 0; i < stringToCheck.length(); i++) {
    if (stringToCheck[i] == ' ') {
      continue;
    }
    newString += stringToCheck[i];
  }
  return newString;
}

bool WordToolbox::checkAnagram(string stringToCheck) {
  string stringWithoutSpaces = removeSpaces(stringToCheck);
  string toCheck = getString();
  if (stringWithoutSpaces.length() != toCheck.length()) {
    return false;
  }
  sort(stringWithoutSpaces.begin(), stringWithoutSpaces.end());
  sort(toCheck.begin(), toCheck.end());
  
  for (int i = 0; i < toCheck.length(); i++) {
    if (toCheck[i] != stringWithoutSpaces[i]) {
      return false;
    }
  }
  return true;
}

int WordToolbox::countHowMany(char charToFind) {
  int counter = 0;
  for (int i = 0; i < stringHeld.length(); i++) {
    if (stringHeld[i] == charToFind) {
      counter++;
    }
  }
  return counter;
}

WordToolbox::~WordToolbox() {
}
