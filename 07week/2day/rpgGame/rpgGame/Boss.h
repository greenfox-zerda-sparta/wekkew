#pragma once

#include "Character.h"

using namespace std;

class Boss : public Character {
public:
  Boss();
  void drawBoss(GameContext&);
  ~Boss();
};

