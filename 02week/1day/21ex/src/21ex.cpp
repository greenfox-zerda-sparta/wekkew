#include <iostream>
#include <string>

using namespace std;

int main() {
	int z = 13;
	// if z is between 10 and 20 print 'Sweet!'
	// if less than 10 print 'More!',
	// if more than 20 print 'Less!'
	if (z > 20) {
		cout << "Less!";
	}
	else {
		if (z > 10) {
			cout << "Sweet!";
		}
		else {
		cout << "More!";
		}
	}
	return 0;
}
