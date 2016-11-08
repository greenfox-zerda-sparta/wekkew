/*
 * Character.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

namespace std {

enum CharacterType {HUMAN, ORC, DWARF, ELF};

class Character {
public:
  Character(string, CharacterType, int, int, int);
  void attackTo(Character&);
  virtual ~Character();
private:
  string name;
  CharacterType charType;
  int health;
  int attack;
  int defense;
  void fight(Character&, Character&);
};

} /* namespace std */

#endif /* CHARACTER_H_ */



