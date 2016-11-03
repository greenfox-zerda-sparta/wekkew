#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

void carStat(Car pkw) {
  cout << pkw.type << endl;
  cout << pkw.km << endl;
  if (pkw.type != TESLA) {
    cout << pkw.gas;
  }
}

int main() {
  Car toyota = {VOLVO, 1234, 80};
  carStat(toyota);
  return 0;
}
