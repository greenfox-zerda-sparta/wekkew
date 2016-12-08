#include "Hero.h"

Hero::Hero() {
}

void Hero::drawHero(GameContext& context, int x, int y, string imgName) {
  context.draw_sprite(imgName, x * 72, y * 72);
}

void Hero::moveHero(GameContext& context, vector<vector<int>>& levelTable) {
  if (context.was_key_pressed(ARROW_UP)) { //heroY--
    if (checkWalls(heroX, --heroY, levelTable)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      ++heroY;
    }
    heroView = "hero-up.bmp";
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) { //heroX++
    if (checkWalls(++heroX, heroY, levelTable)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      --heroX;
    }
    heroView = "hero-right.bmp";
  }
  else if (context.was_key_pressed(ARROW_DOWN)) { //heroY++
    if (checkWalls(heroX, ++heroY, levelTable)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      --heroY;
    }
    heroView = "hero-down.bmp";
  }
  else if (context.was_key_pressed(ARROW_LEFT)) { //heroX--
    if (checkWalls(--heroX, heroY, levelTable)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      ++heroX;
    }
    heroView = "hero-left.bmp";
  }
  else {
    drawHero(context, heroX, heroY, heroView);
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
