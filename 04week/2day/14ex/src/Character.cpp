/*
 * Character.cpp
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Character.h"

using namespace std;



Character::Character(string name, CharacterType type, int health, int attack, int defense) {
  this->name = name;
  this->charType = type;
  this->health = health;
  this->attack = attack;
  this->defense = defense;
}

void Character::attackTo(Character& foe) {
  srand(time(NULL));
  bool friendlyAttacks = true;
  while (this->health > 0 && foe.health > 0) {
    if (friendlyAttacks) {
      int thisAttack = this->attack*(rand()%2+1);
      if (thisAttack > foe.defense) {
        foe.health -= thisAttack - foe.defense;
        cout << foe.name << " has lost: " << thisAttack - foe.defense << " health" << endl;
      }
      else {
        this->health -= (foe.defense - thisAttack);
        cout << this->name << " has lost: " << (foe.defense - thisAttack) << " health" << endl;
      }
      friendlyAttacks = !friendlyAttacks;
    }
    else {
      int foeAttack = foe.attack*(rand()%2+1);
      if (foeAttack > this->defense) {
        this->health -= (foeAttack - this->defense);
        cout << this->name << " has lost: " << (foeAttack - this->defense) << " health" << endl;
      }
      else {
        foe.health -= (this->defense - foeAttack);
        cout << foe.name << " has lost: " << (this->defense - foeAttack) << " health" << endl;
      }
      friendlyAttacks = !friendlyAttacks;
    }
  cout << endl << this->name << " health: " << this->health << "  |  " << foe.name << " health: "<< foe.health << endl << endl;
  }
  if (this->health > 0) {
    cout << this->name << " has won the fight!" << endl;
  }
  else {
    cout << foe.name << " has won the figth!" << endl;
  }
}

//attacking method which takes a character class and decreases its health value
// with (current character class attack - input character class defense),
//if the output is minus, then our health is decreased
//set the attacking method to have 50% chance to count our attack value twice,
//(2xcurrent attack - input defense) before calculating the final health points.

Character::~Character() {
  // TODO Auto-generated destructor stub
}
