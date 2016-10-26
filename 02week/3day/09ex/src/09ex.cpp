#include <iostream>
#include <string>
using namespace std;

// Write this function so that it appends the variable addition to the other variable base.
// Base should be changed, addition should remain the same.
void concatenate(string *base, string *addition) {
	*base += *addition;
}

int main(int argc, char** argv) {
	string a = "kuty";
	string b = "a es macska";

	concatenate(&a, &b);

	cout << "What's the result: " << a << endl;
	cout << "Did it remain unchanged? " << b << endl;

}
