#include "Keyboard.h"

using namespace std;

Keyboard::Keyboard() {
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_CreateWindow("Keyboard",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      800, 400,
      0);
    renderer = SDL_CreateRenderer(screen, -1, 0);
    fillVector();
}

void Keyboard::loadAnDrawAllFiles() {
  string start = "./keyboard/";
  string end = ".bmp";
  for (int i = 0; i < fileNames.size(); i++) {
    string path = "";
    path += start;
    path += fileNames[i];
    path += end;
    loadFile(path);
    drawSprite(path, i * 100, 0);
  }
  render();
}

void Keyboard::loadAnDrawAllFiles(int number) {
  string start = "./keyboard/";
  string pushStart = "./keyboard/push";
  string end = ".bmp";
  for (int i = 0; i < fileNames.size(); i++) {
    string path = "";
    if (i != number) {
      path += start;
    } else {
      path += pushStart;
    }
    path += fileNames[i];
    path += end;
    loadFile(path);
    drawSprite(path, i * 100, 0);
  }
  render();
  Sleep(100);
  loadAnDrawAllFiles();
}

void Keyboard::fillVector() {
  fileNames.push_back("c");
  fileNames.push_back("d");
  fileNames.push_back("e");
  fileNames.push_back("f");
  fileNames.push_back("g");
  fileNames.push_back("a");
  fileNames.push_back("h");
  fileNames.push_back("capC");
}

void Keyboard::loadFile(string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(screen)), 0xFF, 0, 0xFF));
  sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}

void Keyboard::drawSprite(string name, int x, int y) {
  SDL_Rect temp;
  temp.x = x;
  temp.y = y;
  temp.w = 100;
  temp.h = 400;
  SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
}

void Keyboard::render() {
  SDL_RenderPresent(renderer);
}

Keyboard::~Keyboard() {
  for (std::map<std::string, SDL_Texture*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  SDL_Quit();
}
