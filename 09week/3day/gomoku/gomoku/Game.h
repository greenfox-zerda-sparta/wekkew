#pragma once

#include "GameContext.h"

class Game {
public:
  virtual void init(GameContext& context) = 0;
  virtual void render(GameContext& context) = 0;
  virtual void makeStep(int, int) = 0;
};
