#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "Header.h"
using namespace std;


//int main() {
//  int n;
//  int k;
//  cin >> n >> k;
//  vector<int> x(n);
//  for (int x_i = 0; x_i < n; x_i++) {
//    cin >> x[x_i];
//  }
//  double diff = get_diff(x);
//  double range = get_coverage(n);
//  double needed = ceil(diff / range);
//  cout << needed << endl;
//  return 0;
//}

int get_diff(vector<int>);

int get_coverage(int);

int main() {
  /*int n = 1;
  int k = 5;
  vector<int> x = { 1, 2, 3, 4, 5 };*/

  //int n = 2;
  //int k = 8;
  //vector<int> x = { 7, 2, 4, 6, 5, 9, 12, 11 };

  int n = 2;
  int k = 7;
  vector<int> x = { 9, 5, 4, 2, 6, 15, 12 };

 /* int n = antenna;
  int k = long_victor.size();
  vector<int> x = long_victor;*/

  int diff = get_diff(x);
  int range = get_coverage(n);
  int needed = diff % range != 0 ? diff/range+1:diff/range;
  cout << "diff: " << diff << ", range: " << range << endl << "needed transistors: " << needed << endl;
  return 0;
}

int get_diff(vector<int> victor) {
  int min = *min_element(victor.begin(), victor.end());
  int max = *max_element(victor.begin(), victor.end());
  return (max - min) + 1;
}

int get_coverage(int range) {
  return (range * 2) + 1;
}