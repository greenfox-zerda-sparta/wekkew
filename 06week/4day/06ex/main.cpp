#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void manipulateVector(vector <double>& d) {
  double temp = d[d.size()-1];
  d.pop_back();
  int index = rand() % d.size();
  d[index] += temp;
}

int main() {
	//create a vector of doubles with the size of 30, with every element equal of 1.5
	//create functions that takes this vector, pick the last element of it and adding its value to
	//an other item from the vector(this item place is random) and remove the last element at the end
	//run this function 20 times, then print every element of the vector
	vector<double> d(30, 1.5);
	for (int i = 0; i < 20; i++) {
  	manipulateVector(d);
	}
	for (int i = 0; i < d.size(); i++) {
    cout << d[i] << " | ";
  }
  cout << endl;
  return 0;
}
