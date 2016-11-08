/*
 * Character.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

namespace std {

enum CharacterType {Human, Monster};

class Character {
public:
  Character(string name, CharacterType type, int health, int attack, int defense);
  void attackTo(Character);
  virtual ~Character();
private:
  string name;
  CharacterType charType;
  int health;
  int attack;
  int defense;
};

} /* namespace std */

#endif /* CHARACTER_H_ */



