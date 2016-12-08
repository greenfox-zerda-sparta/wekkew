#pragma once

#include "game-engine.h"

using namespace std;

class Skeleton {
public:
  Skeleton(vector<vector<int>>& victor);
  void drawSkeleton(GameContext&, int, int);
  virtual ~Skeleton();
public:
  int boneX = 0;
  int boneY = 0;
};

