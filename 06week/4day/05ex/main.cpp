#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


int main() {
	//create a vector of integers with the size of 10, fill them with random numbers
	//create a vector of doubles and reserve place for 10 items
	//push an item to the end of the vector with the double
	//print which vectors size is higher (and why?)
  vector<int> v(10);
  for (int i = 0; i < v.size(); i++) {
    v[i] = rand() % v.size();
  }

  vector<double> d(10);
  d.push_back(2.5);

  d.size()>v.size()?cout << "double":cout << "integer";


  return 0;
}
