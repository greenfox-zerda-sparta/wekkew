#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int letterCounter(string str, char letter) {
	int stringLength = str.length();
	int counter = 0;
	for (int index = 0; index < stringLength; index++) {
		if (str[index] == letter) {
			counter += 1;
		}
	}
	return counter;

}

int main() {
  string word = "makkoshotyka-also";
  char letter = 'o';
  // Write a function that takes a string and a character, and counts how many
  // times the character occures in the string and it should return a number
  cout << letterCounter(word, letter);
  return 0;
}
