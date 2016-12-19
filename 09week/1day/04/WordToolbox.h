#ifndef WORDTOOLBOX_H
#define WORDTOOLBOX_H

#include <string>

using namespace std;


class WordToolbox {
private:
  string stringHeld;
  string removeSpaces(string);
  int countHowMany(char, string);
  string getString();
public:
  WordToolbox(string);
  void setString(string);
  bool checkAnagram(string);
  bool checkWithCount(string);
  ~WordToolbox();
};

#endif
