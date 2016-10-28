#include <iostream>
#include <string>

using namespace std;
const int ansLength = 100;
string answere[ansLength] = {};

string createPalindrome(string word) {
  string temp = "";
  for (unsigned int i = 0; i < word.length(); i++) {
       temp += word[word.length()-1-i];
  }
  return word + temp;
}

void checkPalindrom(int index) {
  string currAns = answere[index];
  int currAnsLeng = currAns.length();
  bool palindrome = true;
  for (int i = 1; i < currAnsLeng/2; i++) {
    if(currAns[i] != currAns[currAnsLeng-i-1]){
      palindrome = false;
    }
  }
  if (palindrome) {
    cout << currAns << endl;;
  }
}

void searchPalindromes(string text) {
  int maxLength = text.length();

  int ansInd = 0;
  for (int paLength = 3; paLength < maxLength; paLength+=1) {
    int palNum = paLength-1;
    for (int i = 0; i < maxLength-palNum; i++) {
      if (text[i] == text[i+palNum]) {
        for (int palIndex = 0; palIndex < paLength; palIndex++) {
          answere[ansInd] += text[i+palIndex];
        }
        ansInd++;
      }
    }
  }
  for (int i = 0; i < ansLength; i++) {
    if (answere[i].length() > 0) {
      checkPalindrom(i);
    }
  }
}

int main() {
  string output = createPalindrome("pear");
  cout << output << endl << endl;

  searchPalindromes("dog goat dad duck doiodle never neen");

  // it prints: ['og go', ' dad ', 'd d', 'dood', 'eve']

  return 0;
}
