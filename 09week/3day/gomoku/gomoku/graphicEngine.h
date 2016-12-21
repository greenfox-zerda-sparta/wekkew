#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

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
  GameContext(unsigned int screen_width, unsigned int screen_height) {
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, 0);
    renderer = SDL_CreateRenderer(screen, -1, 0);
  }

  ~GameContext() {
    for (map<string, SDL_Texture*>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
      SDL_DestroyTexture(it->second);
    }
    SDL_Quit();
  }

  void load_file(string name) {
    SDL_Surface* result = SDL_LoadBMP(name.c_str());
    SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(screen)), 0xFF, 0, 0xFF));
    sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
    SDL_FreeSurface(result);
  }

  void draw_sprite(string name, int x, int y) {
    SDL_Rect temp;
    temp.x = x;
    temp.y = y;
    temp.w = 72;
    temp.h = 72;
    SDL_RenderCopy(renderer, sprites[name], NULL, &temp);
  }

  void render() {
    SDL_RenderPresent(renderer);
  }

};

class Game {                                 
public:
  virtual void init(GameContext& context) = 0;
  virtual void render(GameContext& context) = 0;
};  
//interfész

class GameEngine {
private:
  GameContext* context;
  Game* game;
public:
  GameEngine(Game* g, unsigned int screen_width, unsigned int screen_height) {
    context = new GameContext(screen_width, screen_height);
    game = g;
    game->init(*context);
  }
  ~GameEngine() {
    delete context;
  }
  void run() {
    SDL_Event event;
    bool gameover = false;

    while (gameover) {
      if (SDL_PollEvent(&event)) {

        switch (event.type) {
        case SDL_QUIT:
          gameover = true;
          break;
        case SDL_KEYDOWN:

          switch (event.key.keysym.sym) {
          case SDLK_ESCAPE:
            cout << "szia Fruzsi" << endl;
          case SDLK_q:
            gameover = true;
            cout << "szia Mate" << endl;
            break;
          }

        }

      }

      game->render(*context);
    }
  }

};
#endif