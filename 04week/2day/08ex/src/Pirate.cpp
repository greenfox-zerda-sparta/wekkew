#include <iostream>
#include <string>
#include "Pirate.h"

using namespace std;

Pirate::Pirate() {
  this->drinkCount = 0;

}

void Pirate::drinkRun() {
  cout << "DRINK!" << endl;
  this->drinkCount++;
}

void Pirate::howsGoingMate() {
  if (this->drinkCount >= 5) {
    cout << "Arrrrrr!" << endl;
  } else {
    cout << "Nope, nothin'" << endl;
  }
}

Pirate::~Pirate() {
  // TODO Auto-generated destructor stub
}

