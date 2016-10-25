#include <iostream>
using namespace std;

void alphabetSlicer(char beginner, char array[6]) {
	char start = beginner;
	for (int index = 0; index < 5; index++) {
		if (start + index > 122) {
			start -= 26;
		}
		array[index] = start + index;
	}
	array[5] = '\0';

}



//Implement the above declared function to return the next 5 characters in the English alphabet
//after the character 'beginner' in an array of characters.
//The last character of the array should be '\0'.
//If there are less then 5 characters left after 'beginner' start from the beginning.
//So, alphabetSlicer(y) should return {'z','a','b','c','d','\0'}

int main(int argc, char** argv){
	char arr[6];
	alphabetSlicer('d', arr);
	cout << arr << endl;
	alphabetSlicer('w', arr);
	cout << arr << endl;


	return 0;
}
