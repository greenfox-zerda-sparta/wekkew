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

void fight(Character enemy, Character friendly) {

}

void Character::attackTo(Character enemy) {
  srand(time(NULL));
  int attackForce = this->attack; // * ceil(rand() % 2 + 1);
  int defenseForce = enemy.defense;
  while (this->health > 0 || enemy.health > 0) {

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
