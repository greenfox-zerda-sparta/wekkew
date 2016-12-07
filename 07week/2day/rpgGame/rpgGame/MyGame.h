#pragma once
#include "game-engine.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>

using /*motherfucker*/ namespace std;

static int heroX = 0;
static int heroY = 0;
static string heroView = "hero-down.bmp";
static int skeletonCounter = 0;

class MyGame : public Game {
public:
  MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  void drawTable(GameContext& context);
  void drawHero(GameContext& context, int x, int y, string imgName);
  void moveHero(GameContext& context);
  bool checkWalls(int x, int y);
  void drawSkeleton(GameContext& context, int x, int y);
  void createSkeletons(GameContext& context);
  void drawBoss(GameContext& context);
  virtual ~MyGame();
public:
  vector<vector<int>> levelTable;
};

