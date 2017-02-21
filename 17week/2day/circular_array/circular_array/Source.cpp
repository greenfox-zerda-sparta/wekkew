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

using namespace std;

void move_vector(vector<int>&, int);


int main() {
  int n;
  int k;
  int q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int a_i = 0; a_i < n; a_i++) {
    cin >> a[a_i];
  }

  move_vector(a, k);

  for (int a0 = 0; a0 < q; a0++) {
    int m;
    cin >> m;
    cout << a[m] << endl;
  }

  return 0;
}

void move_vector(vector<int>& victor, int k) {
  for (int i = 0; i < k; i++) {
    victor.insert(victor.begin(), victor[victor.size() - 1]);
    victor.pop_back();
  }
}