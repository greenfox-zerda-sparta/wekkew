#include "GameContext.h"

GameContext::GameContext(unsigned int screen_width, unsigned int screen_height) {
  SDL_Init(SDL_INIT_EVERYTHING);
  screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, 0);
  renderer = SDL_CreateRenderer(screen, -1, 0);
}

void GameContext::load_file(string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(screen)), 0xFF, 0, 0xFF));
  sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}

void GameContext::draw_sprite(string name, int x, int y) {
  SDL_Rect   temp;
  temp.x = x;
  temp.y = y;
  temp.w = 40;
  temp.h = 40;
  SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
}

void GameContext::draw_sprite(string name, int x, int y, int width, int height) {
  SDL_Rect   temp;
  temp.x = x;
  temp.y = y;
  temp.w = width;
  temp.h = height;
  SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
}

void GameContext::render() {
  SDL_RenderPresent(renderer);
}

GameContext::~GameContext() {
  for (map<string, SDL_Texture*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
    SDL_DestroyTexture(it->second);
  }
  SDL_Quit();
}