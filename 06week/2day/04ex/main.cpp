#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.


string* stringSeparator(string, int);

int main() {
  try {
    cout << stringSeparator("Rebarbara", 2)[0] << " \& " << stringSeparator("Rebarbara", 2)[1] << endl;
    cout << stringSeparator("Rebarbara", 2)[0] << " \& " << stringSeparator("Rebarbara", 19)[1] << endl;
  } catch (char* errorMessage) {
    cout << errorMessage << endl;
  }

  return 0;
}

string* stringSeparator(string originalString, int separate) {
  if (separate > originalString.length()) {
    char* error = "out of bound";
    throw error;
  }
  string* returnArray = new string[2];
  for (int i = 0; i < separate; i++) {
    returnArray[0] += originalString[i];
  }
  for (int i = separate; i < originalString.length(); i++) {
    returnArray[1] += originalString[i];
  }
  return returnArray;
}
