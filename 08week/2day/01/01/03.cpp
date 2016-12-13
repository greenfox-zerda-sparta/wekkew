#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

void printMap(map<string, int>& currentmap) {
  for (map<string, int>::iterator it = currentmap.begin(); it != currentmap.end(); it++) {
    cout << it->first << ":" << it->second << endl;
  }
}

int main3() {
  map<string, int> m;
  m["one"] = 1;
  m["two"] = 2;
  m["three"] = 3;
  m["four"] = 4;
  m["five"] = 5;

  // Print all the keys and values of the map
  printMap(m);

  system("pause");
  return 0;
}