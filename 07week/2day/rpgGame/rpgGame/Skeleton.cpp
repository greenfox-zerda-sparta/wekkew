#include "Skeleton.h"

Skeleton::Skeleton(vector<vector<int>>& victor) {
  posX = rand() % 9 + 1;
  posY = rand() % 9 + 1;
  while (!victor[posY][posX]) {
    posX = rand() % 9 + 1;
    posY = rand() % 9 + 1;
  }
  this->HealthPoint = 2 * (rand() % 6 + 1) + rand() % 6 + 1;
  this->DefensePoint = 2 * (rand() % 6 + 1) + (rand() % 6 + 1) / 2;
  this->StrikePoint = rand() % 6 + 1;
  cout << "Skeleton HP: " << HealthPoint << ", DP: " << DefensePoint << ", SP: " << StrikePoint << endl;
}

void Skeleton::drawSkeleton(GameContext& context, int x, int y) {
  context.draw_sprite("skeleton.bmp", x*72, y*72);
}

Skeleton::~Skeleton() {
}
