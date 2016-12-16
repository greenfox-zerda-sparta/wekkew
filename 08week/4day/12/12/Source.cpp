#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Box.h"

using namespace std;

int addNumbers(vector<Box>& victor) {
  int value = 0;
  if (victor.size() > 0) {

    if (victor[victor.size() - 1].type == INTEGER) {
      value = victor[victor.size() - 1].integer;
      victor.pop_back();
      if (victor.size() == 0) {
        return value;
      } 
      else {
        return value + addNumbers(victor);
      }
    }

    else { 
      value = addNumbers(victor[victor.size() - 1].doboz);
      victor.pop_back();
      return value + addNumbers(victor);
    }
  
  }
  return value;
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
  box21.type = INTEGER;
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
  box311.doboz.push_back(box312);

  Box box313;
  box313.type = INTEGER;
  box313.integer = 5;
  box311.doboz.push_back(box313);

  Box box3;
  box3.type = VECTOR;
  box3.doboz.push_back(box311);

  
  cout << "full " << addNumbers(boxVector) << endl;

  vector<Box> tryvector;
  tryvector.push_back(box1);
  tryvector.push_back(box2);
  tryvector.push_back(box3);

  cout << "box1 + box2 + box3 " << addNumbers(tryvector) << endl;

  cout << "box2 " << addNumbers(box2.doboz) << endl;
  cout << "box3 " << addNumbers(box3.doboz) << endl;

  system("pause");
  return 0;
}