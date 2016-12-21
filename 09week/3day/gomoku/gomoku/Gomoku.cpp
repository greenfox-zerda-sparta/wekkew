#include "Gomoku.h"
#include <iostream>

using namespace std;

Gomoku::Gomoku() {
  win = false;
  stepCounter = 0;
  fillVector();
  startCheck = false;
}

void Gomoku::fillVector() {
  int boardSize = 19;
  for (int i = 0; i < boardSize; i++) {
    vector<unsigned int> row;
    for (int i = 0; i < boardSize; i++) {
      row.push_back(0);
    }
    board.push_back(row);
  }
}

void Gomoku::changElement(unsigned int yCord, unsigned int xCord, unsigned int value) {
  if (isPlaceFreeToModify(yCord, xCord)) {
    board[yCord][xCord] = value;
    stepCounter++;
    startCheck = stepCounter > 8 ? true : false;
  }
}

bool Gomoku::isPlaceFreeToModify(unsigned int yCord, unsigned int xCord) {
  if (board[yCord][xCord] != 0) {
    return false;
  }
  return true;
}

void Gomoku::step(unsigned int yCord, unsigned int xCord) {
  if (stepCounter % 2) {
    changElement(yCord, xCord, 2);
  } else {
    changElement(yCord, xCord, 1);
  }
  if (startCheck) {
    if (check(yCord, xCord)) {
      cout << "MIAFASZ" << endl;
      win = true;
    }
  }
}

bool Gomoku::check(unsigned int yCord, unsigned int xCord) {
  //horizontal back <- check
  for (int i = 1; i < scale; i++) {
    if (board[yCord][xCord] != board[yCord][xCord-i]) {
    return false;
    }
  }
  return true;
}

Gomoku::~Gomoku() {
  fillVector();
}
