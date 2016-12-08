#pragma once

#include "Character.h"

using namespace std;

class Hero: public Character {
public:
  Hero();
  void drawHero(GameContext&, int, int, string);
  void moveHero(GameContext&, vector<vector<int>>&);
  bool checkWalls(int, int, vector<vector<int>>&);
  virtual ~Hero();
private:
  string heroView = "hero-down.bmp";
};

