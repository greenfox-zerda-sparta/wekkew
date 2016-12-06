#include "game-engine.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using /*motherfucker*/ namespace std;

class MyGame : public Game {
public:
  MyGame() {
    ifstream map;
    map.open("map1.txt");
    string line;
    int lineCount = 0;
    for (unsigned int i = 0; i < 10; i++) {
      getline(map, line);
      vector<int> vec;
      table.push_back(vec);
      for (unsigned int j = 0; j < line.length(); j++) {
        if (line[j] == '0') {
          table[i].push_back(0);
        } else {
          table[i].push_back(1);
        }
      }
    }
    map.close();
  }

  virtual void init(GameContext& context) {
    context.load_file("floor.bmp");
    context.load_file("wall.bmp");
  }
  virtual void render(GameContext& context) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (table[i][j] == 1) {
          context.draw_sprite("floor.bmp", j * 72, i * 72);
        } else {
          context.draw_sprite("wall.bmp", j * 72, i * 72);
        }
      }
    }
    context.render();
  }
private:
  vector<vector<int>> table;
};

int main(int argc, char* argv[]) {
  MyGame game;
  GameEngine engine(&game, 720, 720);
  engine.run();
  return 0;
}