#include "MyGame.h"

MyGame::MyGame() {
  srand(time(NULL));
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
  context.load_file("skeleton.bmp"); 
  context.load_file("boss.bmp");
}

void MyGame::render(GameContext& context) {
  drawTable(context);
  moveHero(context);
  createSkeletons(context);
  
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

void MyGame::drawHero(GameContext& context, int x, int y, string imgName) {
  context.draw_sprite(imgName, x*72, y*72);
}

void MyGame::moveHero(GameContext& context) {
  if (context.was_key_pressed(ARROW_UP)) { //heroY--
    if (checkWalls(heroX, --heroY)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      ++heroY;
    }
    heroView = "hero-up.bmp";
    cout << "UP" << endl;
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) { //heroX++
    if (checkWalls(++heroX, heroY)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      --heroX;
    }
    heroView = "hero-right.bmp";
    cout << "RIGHT" << endl;
  }
  else if (context.was_key_pressed(ARROW_DOWN)) { //heroY++
    if (checkWalls(heroX, ++heroY)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      --heroY;
    }
    heroView = "hero-down.bmp";
    cout << "DOWN" << endl;
  }
  else if (context.was_key_pressed(ARROW_LEFT)) { //heroX--
    if (checkWalls(--heroX, heroY)) {
      drawHero(context, heroX, heroY, heroView);
    }
    else {
      ++heroX;
    }
    heroView = "hero-left.bmp";
    cout << "LEFT" << endl;
  }
  else {
    drawHero(context, heroX, heroY, heroView);
  }
}

bool MyGame::checkWalls(int x, int y) {
  if (x < 0 || y < 0 || x > 9 || y > 9) {
    return false;
  }
  if (levelTable[y][x] == 0) {
    return false;
  }
  return true;
}

void MyGame::drawSkeleton(GameContext& context, int x, int y) {
  cout << "x: " << x << " y: " << y << endl;
  context.draw_sprite("skeleton.bmp", x * 72, y * 72);
}

void MyGame::createSkeletons(GameContext& context) {
  int i = 0;
  while (skeletonCounter < 3) {
    int x = rand() % 8 + 1;
    int y = rand() % 8 + 1;
    if (checkWalls(x, y)) {
      drawSkeleton(context, x, y);
      skeletonCounter++;
    }
    else {
      createSkeletons(context);
    }
  }
}

MyGame::~MyGame() {
}
