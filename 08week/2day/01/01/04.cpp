#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and 
// it should have integers as values that represents how many times the
// letter appeared int the string

void printMap(map<char, int>& currentmap) {
  for (map<char, int>::iterator it = currentmap.begin(); it != currentmap.end(); it++) {
    cout << it->first << ":" << it->second << endl;
  }
}

bool ifMapContainsKey(map<char, int>& stringmap, char a) {
  for (map<char, int>::iterator it = stringmap.begin(); it != stringmap.end(); it++) {
    if (a == it->first) {
      return true;
    }
  }
  return false;
}

void stringToMap(string word, map<char, int>& stringmap) {
  for (int i = 0; i < word.length(); i++) {
    if (ifMapContainsKey(stringmap, word[i])) {
      stringmap[word[i]] += 1;
    } else {
      stringmap[word[i]] = 1;
    }
  }
}

int main4() {
  string word = "megszentsegtelentithetetlenkedesitekert";
  map<char, int> wordmap;

  stringToMap(word, wordmap);
  printMap(wordmap);

  system("pause");
  return 0;
}