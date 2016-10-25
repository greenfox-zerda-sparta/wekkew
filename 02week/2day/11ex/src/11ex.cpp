#include <iostream>
#include <string>

using namespace std;

string addA(string s) {
	s += "a";
	return s;
}

int main() {
  string k = "kuty";
  // write a function that gets a string as an input
  // and appends an 'a' character to its end
  cout << addA(k);
  return 0;
}
