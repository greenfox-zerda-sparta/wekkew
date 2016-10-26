#include <iostream>
#include <string>
using namespace std;

// Create a function that prints each word in a string into a new line!
void printWords(string text) {
	int length = text.length();
	for (int i = 0; i < length; i++) {
		cout << text[i];
		if (text[i] == ' ') {
			cout << endl;
		}
	}
}
// Create an other function that takes a string and an array of strings as it's input
// and puts each word in the original string into a new element in the array of strings.
int wordCounter(string text) {
	int length = text.length();
	int counter = 1;
	for (int i = 0; i < length; i++) {
		if (text[i] == ' ') {
			counter++;
		}
	}
	return counter;
}

void stringToArray(string text) {
	string array[wordCounter(text)];
	int arrayIndex = 0;
	int words = wordCounter(text);
	for (unsigned int i = 0; i < text.length(); i++) {
		if (text[i] != ' ') {
			array[arrayIndex] += text[i];
		}
		else {
			arrayIndex++;
			continue;
		}
	}
	for (int i = 0; i < words; i++) {
		cout << array[i] << endl;
	}
}

// Decide which argument should be a pointer and which shouldn't.
// In the main function, print out each element of the array into a new line!


int main(int argc, char **argv){
	string text1 = "i believe that if life gives you lemons";
	string text2 = " you should make lemonade";
	string text3 = " and try to find somebody whose life has given them vodka";
	string text4 = " and have a party";
	stringToArray(text1);
	stringToArray(text2);
	stringToArray(text3);
	stringToArray(text4);
//	printWords(text1);
//	printWords(text2);
//	printWords(text3);
//	printWords(text4);

	return 0;
}
