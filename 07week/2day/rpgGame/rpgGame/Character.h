#pragma once

#include "game-engine.h"

class Character {
public:
  Character();
  virtual ~Character();
  int HealthPoint;
  int DefensePoint;
  int StrikePoint;
  int posX;
  int posY;
};

