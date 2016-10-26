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

// Decide which argument should be a pointer and which shouldn't.
// In the main function, print out each element of the array into a new line!


int main(int argc, char **argv){
	string text1 = "i believe that if life gives you lemons";
	string text2 = " you should make lemonade";
	string text3 = " and try to find somebody whose life has given them vodka";
	string text4 = " and have a party";
	printWords(text1);
	printWords(text2);
	printWords(text3);
	printWords(text4);

	return 0;
}
