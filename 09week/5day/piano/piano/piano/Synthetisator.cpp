#include "Synthetisator.h"

#include <iostream>

using namespace std;

Synthetisator::Synthetisator() {
  keyboard.loadAnDrawAllFiles();
  fillKeyEvent();
}

void Synthetisator::fillKeyEvent() {
  keyEvent[99] = 0;
  keyEvent[100] = 1;
  keyEvent[101] = 2;
  keyEvent[102] = 3;
  keyEvent[103] = 4;
  keyEvent[97] = 5;
  keyEvent[104] = 6;
  keyEvent[1073742049] = 7;
}

void Synthetisator::manageEvent(int keyCode) {
  cout << keyCode << endl;
  voices.playSound(keyCode);
  keyboard.loadAnDrawAllFiles(keyEvent[keyCode]);
}

Synthetisator::~Synthetisator() {
}
