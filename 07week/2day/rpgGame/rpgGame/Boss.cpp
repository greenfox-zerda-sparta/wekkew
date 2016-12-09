#include "Boss.h"

Boss::Boss() {
  this->posX = 9;
  this->posY = 9;
  this->HealthPoint = 2 * (rand() % 6 + 1) + rand() % 6 + 1;
  this->DefensePoint = 2 * (rand() % 6 + 1) + (rand() % 6 + 1) / 2;
  this->StrikePoint = rand() % 6 + 1;
  this->picName = "boss.bmp";
  cout << "Boss HP: " << HealthPoint << ", DP: " << DefensePoint << ", SP: " << StrikePoint << endl;
}

Boss::~Boss() {
}
