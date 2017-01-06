#pragma once

#include <SDL.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameContext {
private:
  SDL_Window* screen;
  SDL_Renderer* renderer;
  map<string, SDL_Texture*> sprites;
public:
  GameContext(unsigned int, unsigned int);
  ~GameContext();
  void load_file(string);
  void draw_sprite(string, int, int);
  void draw_sprite(string, int, int, int, int);
  void render();
};