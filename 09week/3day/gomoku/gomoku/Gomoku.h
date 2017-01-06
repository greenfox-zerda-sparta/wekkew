#pragma once

#include <vector>

using std::vector;

class Gomoku {
private:  
  int requiredElements = 4;
  unsigned int stepCounter;
  const unsigned int size = 19;
  const unsigned int scale = 5;
public:
  vector<vector<unsigned int>> board;
  bool victory;
public:
  Gomoku();
  ~Gomoku();
  void step(int, int);
private:
  void fillVector();
  void changElement(int, int, unsigned int);
  bool isPlaceFreeToModify(int, int);
  bool check(int, int);
  bool horizontalCheck(int, int);
  bool verticalCheck(int, int);
  bool diagonalNWCheck(int, int);
  bool diagonalNECheck(int, int);
  void win(int, int);
  void printBoard();
};
