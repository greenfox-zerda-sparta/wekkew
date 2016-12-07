#pragma once
#include "game-engine.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using /*motherfucker*/ namespace std;

static int heroX = 0;
static int heroY = 0;
static string heroView = "hero-down.bmp";

class MyGame : public Game {
public:
  MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void drawTable(GameContext& context);
  void drawHero(GameContext& context, int x, int y, string imgName);
  void moveHero(GameContext& context);
  void checkWalls(int x, int y);
  virtual ~MyGame();
public:
  vector<vector<int>> levelTable;
};

