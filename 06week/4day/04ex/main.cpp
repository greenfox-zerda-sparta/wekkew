#include <iostream>
#include <vector>


using namespace std;

void addToKarcsi();
vector<char> karcsi(0);
int main() {
	//create a vector of chars with the size of zero;
	//write a function where the user can add characters to the end of this vector

  addToKarcsi();

  return 0;
}

void addToKarcsi() {
  char alma;
  cout << "enter a character:" << endl << "if you enter \"Q\" the program stops running and writi out all the characters" << endl;
  cin >> alma;
  if (alma == 'Q') {
    for (int i = 0; i < karcsi.size(); i++){
      cout << karcsi[i] << " | ";
    }
    cout << endl;
    return;
  }
  karcsi.push_back(alma);
  addToKarcsi();
}
