#include "Skeleton.h"

Skeleton::Skeleton(vector<vector<int>>& victor) {
  boneX = rand() % 9 + 1;
  boneY = rand() % 9 + 1;
  while (!victor[boneY][boneX]) {
    boneX = rand() % 9 + 1;
    boneY = rand() % 9 + 1;
  }
}

void Skeleton::drawSkeleton(GameContext& context, int x, int y) {
  context.draw_sprite("skeleton.bmp", x*72, y*72);
}

Skeleton::~Skeleton() {
}
