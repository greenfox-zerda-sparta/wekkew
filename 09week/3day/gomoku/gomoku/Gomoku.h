#pragma once

#include <vector>

using namespace std;

class Gomoku {
public:
  bool startCheck;
  bool win;
  unsigned int stepCounter;
  const unsigned int size = 19;
  const unsigned int scale = 5;
  vector<vector<unsigned int>> board;
public:
  Gomoku();
  ~Gomoku();
  bool check(unsigned int, unsigned int);
  void step(unsigned int, unsigned int);
private:
  void changElement(unsigned int, unsigned int, unsigned int);
  bool isPlaceFreeToModify(unsigned int, unsigned int);
  void fillVector();
};
