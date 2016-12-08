#pragma once

#include "game-engine.h"

using /*mmotherfucker*/ namespace std;

class TableGenerator  {
public:
  TableGenerator();
  int checkNeighbours(int x, int y);
  void writeToFile();
  void fillRandom();
  virtual ~TableGenerator();
private:
  vector<vector<int>> generatedTable;
};

