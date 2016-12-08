#pragma once

#include "game-engine.h"

using namespace std;

class Hero {
public:
  Hero();
  void drawHero(GameContext&, int, int, string);
  void moveHero(GameContext&, vector<vector<int>>&);
  bool checkWalls(int, int, vector<vector<int>>&);
  virtual ~Hero();
private:
  int heroX = 0;
  int heroY = 0;
  string heroView = "hero-down.bmp";
};

