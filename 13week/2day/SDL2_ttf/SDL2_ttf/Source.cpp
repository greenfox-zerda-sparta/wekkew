#include "TrueTypeFont.h"
#include <iostream>

void InitSDL();



int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("TextToFont", 0, 30, 640*2, 480*2, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  TrueTypeFont* apple = new TrueTypeFont("Arial.ttf", renderer);
  apple->setCordinates(0, 640);
  std::cout << apple->getText() << std::endl;
  apple->setText("Long long time ago, there was a vulcano...");
  std::cout << apple->getText() << std::endl;
  apple->setTextColor(255, 255, 0, 0);
  apple->setBackgroundColor(255, 0, 0, 255);
  SDL_Event event;
  bool running = true;
  while (running) {

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        int x = apple->getXCord();
        int y = apple->getYCord();
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        case SDLK_DOWN:
          apple->setCordinates(x, y + 10);
          break;
        case SDLK_UP:
          apple->setCordinates(x, y - 10);
          break;
        case SDLK_LEFT:
          apple->setCordinates(x - 10, y);
          break;
        case SDLK_RIGHT:
          apple->setCordinates(x + 10, y);
          break;
        }
      }
    }
    apple->render();
  }

  return 0;
} //endof main

void InitSDL() {
  
}