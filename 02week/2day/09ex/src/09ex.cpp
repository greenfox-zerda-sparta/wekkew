#include <iostream>
#include <string>

using namespace std;

void greeting(string i) {
	  cout << "Welcome, Master " << i;
}
int main() {
  string i = "Jozsi";
  // create a function that takes a string argument and greets it.
  greeting(i);
  return 0;
}
