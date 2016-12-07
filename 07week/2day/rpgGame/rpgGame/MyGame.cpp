#include "MyGame.h"

MyGame::MyGame() {
  ifstream map;
  map.open("map1.txt");
  string line;
  int lineCount = 0;
  for (unsigned int i = 0; i < 10; i++) {
    getline(map, line);
    vector<int> vec;
    levelTable.push_back(vec);
    for (unsigned int j = 0; j < line.length(); j++) {
      if (line[j] == '0') {
        levelTable[i].push_back(0);
      }
      else {
        levelTable[i].push_back(1);
      }
    }
  }
  map.close();
}

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-left.bmp");
}

void MyGame::render(GameContext& context) {
  drawTable(context);
  moveHero(context);
  context.render();
}

void MyGame::drawTable(GameContext& context) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (levelTable[i][j] == 1) {
        context.draw_sprite("floor.bmp", j * 72, i * 72);
      }
      else {
        context.draw_sprite("wall.bmp", j * 72, i * 72);
      }
    }
  }
}

void MyGame::drawHero(GameContext & context, int x, int y, string imgName) {
  context.draw_sprite(imgName, x*72, y*72);
}

void MyGame::moveHero(GameContext & context) {
  if (context.was_key_pressed(ARROW_UP)) {
    if (--heroY < 0) {
      heroY = 0;
    }
    heroView = "hero-up.bmp";
    cout << "UP" << endl;
    drawHero(context, heroX, heroY, heroView);
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) {
    if (++heroX > 9) {
      heroX = 9;
    }
    heroView = "hero-right.bmp";
    cout << "RIGHT" << endl;
    drawHero(context, heroX, heroY, heroView);
  }
  else if (context.was_key_pressed(ARROW_DOWN)) {
    if (++heroY > 9) {
      heroY = 9;
    }
    heroView = "hero-down.bmp";
    cout << "DOWN" << endl;
    drawHero(context, heroX, heroY, heroView);
  }
  else if (context.was_key_pressed(ARROW_LEFT)) {
    if (--heroX < 0) {
      heroX = 0;
    }
    heroView = "hero-left.bmp";
    cout << "LEFT" << endl;
    drawHero(context, heroX, heroY, heroView);
  }
  else {
    drawHero(context, heroX, heroY, heroView);
  }
}

void MyGame::checkWalls(int x, int y) {

}

MyGame::~MyGame() {
}
