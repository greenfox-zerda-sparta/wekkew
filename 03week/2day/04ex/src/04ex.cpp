#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int goldSummer(Pirate* pirates, int length) {
  int sum;
  for (int i = 0; i < length; i++) {
    sum += pirates[i].gold_count;
  }
  return sum;
}

float goldAverage(Pirate* pirates, int length) {
  return float(goldSummer(pirates, length))/length;
}

string richestWoodenLeg(Pirate* pirates,int length) {
  int rich = 0;
  int richIndex;
  for (int i = 0; i < length; i++) {
    if (pirates[i].has_wooden_leg) {
      if (pirates[i].gold_count > rich) {
        rich = pirates[i].gold_count;
        richIndex = i;
      }
    }
  }
  return pirates[richIndex].name;


}

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };
  int length = sizeof(pirates)/sizeof(Pirate);
  cout << "Yo Ho Ho, this amount of gold we have: " << goldSummer(pirates, length) << " Aaaarrrrgggghhhh!" << endl;
  cout << "Blimey!, this many is the average gold per buccaneer: " << goldAverage(pirates, length) << " Aaaaarrrrgggghh!" << endl;
  cout << "Shiver me timbers! beacouse " << richestWoodenLeg(pirates, length) << " is the richest wooden legged Bucko!" << endl;
  return 0;
}

