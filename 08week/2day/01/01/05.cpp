#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Write a simple program that creates secret santa pairs
// It should read names till the character q is typed to the standard output, 
// than it should print the names as secret santa pairs like:
// Clair - Mike
// Joe - Ron
// Cloe - Clair
// Ron - Cloe
// Mike - Joe

void printDualVector(vector<string>& victor1, vector<string>& victor2) {
  for (int i = 0; i < victor1.size(); i++) {
    cout << victor1[i] << " - " << victor2[i] << endl;
  }
}

bool checkDifferences(vector<string>& victor1, vector<string>& victor2) {
  for (int i = 0; i < victor1.size(); i++) {
    if (victor1[i] == victor2[i]) {
      return false;
    }
  }
  return true;
}

void pairForSanta(vector<string>& victor1) {
  vector<string> victor2 = victor1;
  while (!checkDifferences(victor1, victor2)) {
    random_shuffle(victor2.begin(), victor2.end());
  }
  printDualVector(victor1, victor2);
}

void getNames() {
  cout << "This is Santa Claus's secret help to make pairs for X-mas!" << endl;
  cout << "please enter the individual(!) names one by one," << endl;
  cout << "if you finished, just press \"q\" and enter." << endl;
  srand(time(NULL));
  vector<string> namevector;
  string name;
  while (name != "q") {
    cin >> name;
    if (name != "q") {
      namevector.push_back(name);
    }
  }
  if (namevector.size() > 1) {
    pairForSanta(namevector);
  }
  else {
    cout << "you should enter more than one names!" << endl;
    getNames();
  }
}

int main5() {
  getNames();
  /*
  Needed feature:
  write to file as follows: 
  filename : first 
  content: second
  */
  system("pause");
  return 0;
}