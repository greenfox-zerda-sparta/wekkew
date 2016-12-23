#pragma once
#include <SDL.h>
#include <map>
#include <vector>
#include <Windows.h>

using namespace std;

class Keyboard {
private:
  SDL_Window* screen;
  SDL_Renderer* renderer;
  map<string, SDL_Texture*> sprites;
  vector<string> fileNames;
public:
  Keyboard();
  void fillVector();
  void loadAnDrawAllFiles();
  void loadAnDrawAllFiles(int);
  void loadFile(string);
  void drawSprite(string, int, int);
  void render();
  ~Keyboard();
};

