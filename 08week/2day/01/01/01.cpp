#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main1() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  for (vector<int>::iterator it = v.begin(); it != v.begin() + 5; it++) {
    cout << *it << endl;
  }
  // Print the first 5 elements of the vector using iterators
  system("pause");

  for_each(v.begin(), v.begin() + 5, [](int element) {cout << element << endl;});

  system("pause");
  return 0;
}