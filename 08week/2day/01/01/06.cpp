#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

using namespace std;

int howManyWordsAre = 0;
int howManyKeysAre = 0;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// (You can obtain a free plain text version of the book,
// along with many others, from http://www.gutenberg.org.)
//
// The first 10 lines of your output file should look something like this:
//
// Word              Count
// =======================
// a                 631
// a-piece           1
// abide             1
// able              1
// about             94
// above             3
// absence           1
// absurd            2
//
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

void writeToFile(map<string, int>& currentmap) {
  ofstream textBook;
  textBook.open("aliceWords.txt");
  for (map<string, int>::iterator it = currentmap.begin(); it != currentmap.end(); it++) {
    textBook << it->first << " - " << it->second << "\n";
  }
  textBook.close();
}

void clearWord(string& word) {
  string abc = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  int abcLength = abc.length();
  while (abc.find(word[0]) > abcLength) {
    if (word.length() > 0) {
      word.erase(word.begin());
    }
    else {
      throw("");
    }
  }
  while (abc.find(word.at(word.length() - 1)) > abcLength) {
    if (word.length() > 0) {
      word.pop_back();
    } else {
      throw("");
    }
  }
}

void mapBook(string path) {
  map<string, int> wordCount;
  ifstream book;
  book.open(path);
  cout << "opened the book, start reading" << endl;
  string word;
  while (book >> word) {
    try {
      clearWord(word);
    } catch (...) {
      continue;
    }
    howManyWordsAre++;
    if (wordCount.count(word)) {
      wordCount[word]++;
    } else {
      wordCount[word] = 1;
      howManyKeysAre++;
    }
  }
  cout << "finished reading" << endl;
  book.close();
  writeToFile(wordCount);
}

int main() {
  mapBook("aliceBook.txt");
  
  system("pause");
  return 0;
}