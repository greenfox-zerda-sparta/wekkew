#include "Gomoku.h"
#include <iostream>

using std::cout;
using std::endl;

Gomoku::Gomoku() {
  stepCounter = 0;
  fillVector();
  victory = false;
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

void Gomoku::changElement(int yCord, int xCord, unsigned int value) {
  if (isPlaceFreeToModify(yCord, xCord)) {
    board[yCord][xCord] = value;
    stepCounter++;
  }
}

bool Gomoku::isPlaceFreeToModify(int yCord, int xCord) {
  if (board[yCord][xCord] != 0) {
    return false;
  }
  return true;
}

void Gomoku::step(int yCord, int xCord) {
  if (stepCounter % 2) {
    changElement(yCord, xCord, 2);
  } else {
    changElement(yCord, xCord, 1);
  }
  win(yCord, xCord);
}

bool Gomoku::check(int yCord, int xCord) {
  if (horizontalCheck(yCord, xCord) || verticalCheck(yCord, xCord) || diagonalNECheck(yCord, xCord) || diagonalNWCheck(yCord, xCord)) {
    return true;
  }
  return false;
}

bool Gomoku::horizontalCheck(int yCord, int xCord) {
  for (int xStartCord = xCord - requiredElements; xStartCord <= xCord; xStartCord++) {
    if (xStartCord < 0) {
      continue;
    }
    bool isBoxValid = true;
    for (int i = 0; i <= requiredElements; i++) {
      if (xStartCord + i >= size) {
        isBoxValid = false;
        break;
      }
      if (board[yCord][xCord] == board[yCord][xStartCord + i]) {
        continue;
      }
      else {
        isBoxValid = false;
        break;
      }
    }
    if (isBoxValid) {
      return true;
    }
  }
  return false;
}

bool Gomoku::verticalCheck(int yCord, int xCord) {
  for (int yStartCord = yCord - requiredElements; yStartCord <= yCord; yStartCord++) {
    if (yStartCord < 0) {
      continue;
    }
    bool isBoxValid = true;
    for (int i = 0; i <= requiredElements; i++) {
      if (yStartCord + i >= size) {
        isBoxValid = false;
        break;
      }
      if (board[yCord][xCord] == board[yStartCord + i][xCord]) {
        continue;
      }
      else {
        isBoxValid = false;
        break;
      }
    }
    if (isBoxValid) {
      return true;
    }
  }
  return false;
}

bool Gomoku::diagonalNECheck(int yCord, int xCord) {
  for (int yStartCord = yCord - requiredElements, xStartCord = xCord - requiredElements; yStartCord <= yCord; yStartCord++, xStartCord++) {
    if (yStartCord < 0 || xStartCord < 0) {
      continue;
    }
    bool isBoxValid = true;
    for (int i = 0; i <= requiredElements; i++) {
      if (yStartCord + i >= size || xStartCord + i >= size) {
        isBoxValid = false;
        break;
      }
      if (board[yCord][xCord] == board[yStartCord + i][xStartCord + i]) {
        continue;
      }
      else {
        isBoxValid = false;
        break;
      }
    }
    if (isBoxValid) {
      return true;
    }
  }
  return false;
}

bool Gomoku::diagonalNWCheck(int yCord, int xCord) {
  for (int yStartCord = yCord - requiredElements, xStartCord = xCord + requiredElements; yStartCord <= yCord; yStartCord++, xStartCord--) {
    if (yStartCord < 0 || xStartCord >= size) {
      continue;
    }
    bool isBoxValid = true;
    for (int i = 0; i <= requiredElements; i++) {
      if (yStartCord + i >= size || xStartCord - i < 0) {
        isBoxValid = false;
        break;
      }
      if (board[yCord][xCord] == board[yStartCord + i][xStartCord - i]) {
        continue;
      }
      else {
        isBoxValid = false;
        break;
      }
    }
    if (isBoxValid) {
      return true;
    }
  }
  return false;
}

void Gomoku::printBoard() {
	for (int i = 0; i < board.size(); i++) {
	  for (int j = 0; j < board[i].size(); j++) { 
		cout << board[i][j];
	  }
	  cout << endl;
	}
}

void Gomoku::win(int yCord, int xCord) {
  if (stepCounter > requiredElements * 2 - 1) {
    if (check(yCord, xCord)) {
      victory = true;
      cout << "win" << endl;
    }
  }
}

Gomoku::~Gomoku() {
  fillVector();
}
