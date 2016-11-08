#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(string type, unsigned int km) {
  this->type = type;
  this->km = km;
}

void Car::runCar(unsigned int runKm) {
  this->km += runKm;
}

void Car::printKm() {
  cout << this->km << endl;
}

Car::~Car() {
  // TODO Auto-generated destructor stub
}


