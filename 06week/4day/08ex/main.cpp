#include <iostream>
#include <vector>
#include <string>

using namespace std;

int roundCounter = 0;

void fillCharVector(vector<char>& c) {
	string answere = "GREENFOX";
	if (roundCounter >= c.size()) {
    for (int i = 0; i < c.size(); i++) {
      c[i] = answere[i];
    }
    return;
	}

	cout << "Enter a letter please: " << endl;
	char alma;
	cin >> alma;
	roundCounter++;
	fillCharVector(c);
}

int main() {
	//create a vector of characters with the size of 8
	//ask the user to fill this vector with characters one by one
	//at the end make sure the vector holds the letters of "GREENFOX"
	//so correct the user if he/she gives a different letter from the one we want them to give :)
  vector<char> charVect(8);
  fillCharVector(charVect);

  for (int i = 0; i < charVect.size(); i++) {
  	cout << charVect[i] << " | ";
  }
  cout << endl;

  return 0;
}
