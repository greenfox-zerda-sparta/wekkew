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

class akarmi {
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
    while (!gameover) {
      
      if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
          gameover = true;
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
          case SDLK_q:
            gameover = true;
            break;
          }
        case SDL_MOUSEBUTTONDOWN:
          int x = 0, y = 0;
          SDL_GetMouseState(&x, &y);
          game->makeStep(x, y);
          break;
        }
      }
      game->render(*context);
    }
  }
};
#endif