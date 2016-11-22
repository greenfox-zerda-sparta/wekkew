#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.
const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

string exceptionThrower(int);

int main() {
  try {
    cout << exceptionThrower(4) << endl;
    exceptionThrower(8);
    exceptionThrower(-1);
  } catch (int intError) {
    cout << "index is bigger than the maximum with: " << intError << endl;
  } catch (const char* stringError) {
    cout << stringError << endl;
  }
  return 0;
}

string exceptionThrower(int index) {
  if (index > 5) {
    throw index-5;
  }
  if (index < 0) {
    throw "You should not enter a negative number, moron!";
  }
  return sentence[index];
}
