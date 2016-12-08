#pragma once
#include "game-engine.h"
#include "TableGenerator.h"
#include "Hero.h"
#include "Skeleton.h"

using namespace std;

class MyGame : public Game {
public:
  MyGame();
  void init(GameContext&);
  void render(GameContext&);
  void drawTable(GameContext&);
  void fillThomb();
  virtual ~MyGame();
public:
  vector<vector<int>> levelTable;
private:
  Hero hero;
  vector<Skeleton> thomb;
};