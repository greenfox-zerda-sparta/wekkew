#pragma once

#include "Gomoku.h"
#include "GameEngine.h"

class Controller: public Game {
public:
  Gomoku* model;
public:
  Controller();
  ~Controller();
  void init(GameContext& context);
  void render(GameContext& context);
  void drawTable(GameContext& context);
  void makeStep(int, int);
private:
  int width;
  int heigth;
};
