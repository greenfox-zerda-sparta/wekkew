#include "car.h"
#include <vector>
using namespace std;

string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string numbers = "0123456789";
string carTypes[18] = {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini"};
string carColors[10] = {"Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér"};

car::car() {

  this->color = carColors[rand() % 10];
  this->type = carTypes[rand() % 18];
  for (int i = 0; i < 3; i++) {
    this->plate += abc[rand()%25];
  }
  this->plate += "-";
  for (int i = 0; i < 3; i++) {
    this->plate += numbers[rand()%10];
  }
}

string car::getData() {
  return this->color + " " + this->type + " " + this->plate;
}


car::~car() {

}
