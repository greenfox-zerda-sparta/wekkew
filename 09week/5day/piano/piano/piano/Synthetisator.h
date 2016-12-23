#pragma once
#include "Keyboard.h"
#include "Voices.h"

class Synthetisator {
public:
  Keyboard keyboard;
  Voices voices;
  map<int, int> keyEvent;
public:
  Synthetisator();
  void fillKeyEvent();
  void manageEvent(int);
  ~Synthetisator();
};

