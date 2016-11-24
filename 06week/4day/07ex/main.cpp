#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void fillVector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    v[i] = rand() % 10;
  }
}

void printVector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " | ";
  }
  cout << endl;
}

void removeEvenNumbersFromVector(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i]%2 == 0) {
      v.erase(v.begin()+i);
      i--;
    }
  }
}
int main() {
	//create a vector of integers with the size of 20
	//fill this vector with random numbers from 0 to 10
	//print the items of the vector
	//remove the even numbers, then print the items again
  vector<int> intV(20);
  fillVector(intV);
  printVector(intV);
  removeEvenNumbersFromVector(intV);
  printVector(intV);

  return 0;
}
