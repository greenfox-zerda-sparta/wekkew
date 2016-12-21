#pragma once
#include "graphicEngine.h"

class MyGame : public Game {
public:
  MyGame();
  ~MyGame();
  void init(GameContext& context);
  void render(GameContext& context);
};

