#pragma once

#include "Character.h"

using namespace std;

class Hero: public Character {
public:
  Hero();
  void moveHero(GameContext&, vector<vector<int>>&);
  void checkEnemy(vector<vector<int>>&);
  bool checkStep(int, int, vector<vector<int>>&);
  void fight();
  virtual ~Hero();
};

