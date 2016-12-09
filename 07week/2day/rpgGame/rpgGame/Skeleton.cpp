#include "Skeleton.h"

Skeleton::Skeleton(vector<vector<int>>& victor) {
  posX = rand() % 8 + 1;
  posY = rand() % 8 + 1;
  while (victor[posY][posX] != 1) {
    posX = rand() % 9 + 1;
    posY = rand() % 9 + 1;
  }
  victor[posY][posX] = 2; /* 0 wall | 1 floor | 2 skeleton */
  this->HealthPoint = 2 * (rand() % 6 + 1);
  this->DefensePoint = 2 * (rand() % 6 + 1);
  this->StrikePoint = rand() % 6 + 1;
  this->picName = "skeleton.bmp";
  cout << "Skeleton HP: " << HealthPoint << ", DP: " << DefensePoint << ", SP: " << StrikePoint << endl;
}

Skeleton::~Skeleton() {
}
