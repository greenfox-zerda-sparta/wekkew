#include "Hero.h"

Hero::Hero() {
  this->HealthPoint = 20 + 3 * (rand() % 6 + 1);
  this->DefensePoint = 2 * rand() % 6 + 1;
  this->StrikePoint = 5 + rand() % 6 + 1;
  this->posX = 0;
  this->posY = 0;
  cout << "Hero HP: " << HealthPoint << ", DP: " << DefensePoint << ", SP: " << StrikePoint << endl;
}

void Hero::drawHero(GameContext& context, int x, int y, string imgName) {
  context.draw_sprite(imgName, x * 72, y * 72);
}

void Hero::moveHero(GameContext& context, vector<vector<int>>& levelTable) {
  if (context.was_key_pressed(ARROW_UP)) { //heroY--
    if (checkWalls(posX, --posY, levelTable)) {
      drawHero(context, posX, posY, heroView);
    }
    else {
      ++posY;
    }
    heroView = "hero-up.bmp";
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) { //heroX++
    if (checkWalls(++posX, posY, levelTable)) {
      drawHero(context, posX, posY, heroView);
    }
    else {
      --posX;
    }
    heroView = "hero-right.bmp";
  }
  else if (context.was_key_pressed(ARROW_DOWN)) { //heroY++
    if (checkWalls(posX, ++posY, levelTable)) {
      drawHero(context, posX, posY, heroView);
    }
    else {
      --posY;
    }
    heroView = "hero-down.bmp";
  }
  else if (context.was_key_pressed(ARROW_LEFT)) { //heroX--
    if (checkWalls(--posX, posY, levelTable)) {
      drawHero(context, posX, posY, heroView);
    }
    else {
      ++posX;
    }
    heroView = "hero-left.bmp";
  }
  else {
    drawHero(context, posX, posY, heroView);
  }
}

bool Hero::checkWalls(int x, int y, vector<vector<int>>& levelTable) {
  if (x < 0 || y < 0 || x > 9 || y > 9) {
    return false;
  }
  if (levelTable[y][x] == 0) {
    return false;
  }
  return true;
}

Hero::~Hero() {
}
