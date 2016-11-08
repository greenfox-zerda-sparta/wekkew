/*
 * Diamond.cpp
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#include "Diamond.h"
#include <iostream>

using namespace std;

Diamond::Diamond(int lines) {
  this->lines = lines;
}

void Diamond::printDiamond() {
  for(int i = 0; i < lines; i++){
    for(int j = lines; j > i; j--){
      cout << " ";
    }
    for(int j = 0; j < i*2-1; j++){
      cout << "*";
    }
    cout << endl;
  }
  for(int i = 0; i < lines; i++){
    for(int j = 0; j < i; j++){
     cout << " ";
    }
    for(int j = 0; j < (lines-i)*2-1; j++){
     cout << "*";
    }
    cout << endl;
  }
}

Diamond::~Diamond() {
  // TODO Auto-generated destructor stub
}


