#pragma once

#include "Character.h"

using namespace std;

class Skeleton: public Character {
public:
  Skeleton(vector<vector<int>>& victor);
  void drawSkeleton(GameContext&, int, int);
  virtual ~Skeleton();
};

