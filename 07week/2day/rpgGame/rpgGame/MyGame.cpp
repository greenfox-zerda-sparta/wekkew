#include "MyGame.h"

MyGame::MyGame() {
  TableGenerator table;
  ifstream map;
  map.open("map.txt");
  string line;
  for (unsigned int i = 0; i < 10; i++) {
    getline(map, line);
    vector<int> vec;
    levelTable.push_back(vec);
    for (unsigned int j = 0; j < 10; j++) {
      if (line[j] == '0') {
        levelTable[i].push_back(0);
      } else if (line[j] == '1') {
        levelTable[i].push_back(1);
      }
    }
  }
  map.close();
  fillThomb();
}

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-left.bmp");
  context.load_file("skeleton.bmp"); 
  context.load_file("boss.bmp");
}

void MyGame::render(GameContext& context) {
  drawTable(context);
  for (unsigned int i = 0; i < thomb.size(); i++) {
    thomb[i].drawSkeleton(context, thomb[i].posX, thomb[i].posY);
  }
  hero.moveHero(context, levelTable);
  context.render();
}

void MyGame::drawTable(GameContext& context) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (levelTable[i][j] == 1) {
        context.draw_sprite("floor.bmp", j * 72, i * 72);
      }
      else if (levelTable[i][j] == 0) {
        context.draw_sprite("wall.bmp", j * 72, i * 72);
      }
      else {
        context.draw_sprite("skeleton.bmp", j * 72, i * 72);
      }
    }
  }
}

void MyGame::fillThomb() {
  int skeletonCount = rand() % 5 + 1;
  cout << skeletonCount << endl;
  while (thomb.size() < skeletonCount) {
    Skeleton boneBoss(levelTable);
    thomb.push_back(boneBoss);
  }
}

MyGame::~MyGame() {
}
