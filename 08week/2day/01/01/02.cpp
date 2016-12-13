#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// create a function that prints a vector using iterators
void printVectorWithIterator(vector<int>& victor) {
  for_each(victor.begin(), victor.end(), [](int element) {cout << element << endl;});
}

int main2() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  printVectorWithIterator(v);

  system("pause");
  return 0;
}