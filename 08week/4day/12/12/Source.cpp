#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Box.h"

using namespace std;

int addNumbers(vector<Box>& victor) {
  int n = victor.size() + 1;
  n--;
  if (n > victor.size()) {
    if (victor[n].type == INTEGER) {
      return victor[n].integer + addNumbers(victor);
    } else {
      addNumbers(victor);
    }
  }
}

int main() {
  // write a recursive function that can add numbers in
  // [1, 2, [3, 4], 1, [1, [2, 4]]]       
   
  vector<Box> boxVector;

  Box box1;
  box1.type = INTEGER;
  box1.integer = 1;
  boxVector.push_back(box1);

  Box box21;
  box21.integer = 2;
  box21.integer = 2;
  
  Box box22;
  box22.type = INTEGER;
  box22.integer = 3;

  Box box2;
  box2.type = VECTOR;
  box2.doboz.push_back(box21);
  box2.doboz.push_back(box22);

  Box box311;
  box311.type = VECTOR;

  Box box312;
  box312.type = INTEGER;
  box312.integer = 4;

  Box box313;
  box313.type = INTEGER;
  box313.integer = 5;

  Box box3;
  box3.type = VECTOR;
  box3.doboz.push_back(box311);

  box311.doboz.push_back(box312);
  box311.doboz.push_back(box313);
  
  cout << addNumbers(boxVector) << endl;

  system("pause");
  return 0;
}