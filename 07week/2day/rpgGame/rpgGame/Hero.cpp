#include "Hero.h"

Hero::Hero() {
  this->HealthPoint = 20 + 3 * (rand() % 6 + 1);
  this->DefensePoint = 2 * rand() % 6 + 1;
  this->StrikePoint = 5 + rand() % 6 + 1;
  this->posX = 0;
  this->posY = 0;
  this->picName = "hero-down.bmp";
  cout << "Hero HP: " << HealthPoint << ", DP: " << DefensePoint << ", SP: " << StrikePoint << endl;
}

void Hero::moveHero(GameContext& context, vector<vector<int>>& levelTable) {
  if (context.was_key_pressed(ARROW_UP)) { //heroY--
    this->picName = "hero-up.bmp";
    if (checkStep(posX, --posY, levelTable)) {
      //drawCharacter(context);
    } else {
      ++posY;
    }
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) { //heroX++
    this->picName = "hero-right.bmp";
    if (checkStep(++posX, posY, levelTable)) {
      drawCharacter(context);
    } else {
      --posX;
    }
  }
  else if (context.was_key_pressed(ARROW_DOWN)) { //heroY++
    this->picName = "hero-down.bmp";
    if (checkStep(posX, ++posY, levelTable)) {
      drawCharacter(context);
    } else {
      --posY;
    }
  }
  else if (context.was_key_pressed(ARROW_LEFT)) { //heroX--
    this->picName = "hero-left.bmp";
    if (checkStep(--posX, posY, levelTable)) {
      drawCharacter(context);
    } else {
      ++posX;
    }
  }
  else {
    drawCharacter(context);
  }
}

void Hero::checkEnemy(vector<vector<int>>& victor) {
  if (victor[posY][posX] == 2) {
    cout << "ENEMY" << endl;
  }
  if (victor[posY][posX] == 3) {
    cout << "BOSS" << endl;
  }
}

bool Hero::checkStep(int x, int y, vector<vector<int>>& levelTable) {
  if (x < 0 || y < 0 || x > 9 || y > 9) {
    return false;
  }
  if (levelTable[y][x] == 0) {
    return false;
  }
  checkEnemy(levelTable);
  return true;
}

void Hero::fight() {

}

Hero::~Hero() {
}
