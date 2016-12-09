#pragma once

#include "game-engine.h"

using namespace std;

class Character {
public:
  Character();
  void drawCharacter(GameContext&);
  virtual ~Character();
public:
  int HealthPoint;
  int DefensePoint;
  int StrikePoint;
  int posX;
  int posY;
  string picName;
};
