#pragma once

#include "Game.h"
#include "Client.h"

class GameEngine {
private:
  GameContext* context;
  Game* game;
  Client* cliens;
  int otherXCord;
  int otherYCord;
public:
  GameEngine(Game*, unsigned int, unsigned int);
  ~GameEngine();
  void run();
  void getOtherPlayerCoordinates(char*);
};