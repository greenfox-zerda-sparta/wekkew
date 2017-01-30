#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

bool isInside(int x, int y, SDL_Rect* rect) {
  if (x < rect->x) {
    return false;
  }
  else if (x > rect->x + rect->w) {
    return false;
  }
  else if (y < rect->y) {
    return false;
  }
  else if (y > rect->y + rect->h) {
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  SDL_Window* window = SDL_CreateWindow("mouseclick event", 0, 30, 640, 480, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  
  std::string path = "button1.png";
  SDL_Surface* surface = IMG_Load(path.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  
  SDL_Rect button = {10, 10, 100, 100};

  SDL_Event event;
  bool running = true;

  while (running) {
    while (SDL_PollEvent(&event)) {
      int x, y;
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        case SDLK_LCTRL:
          std::cout << "This is the left contorl button" << std::endl;
          break;
        }
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&x, &y);
        if (isInside(x, y, &button)) {
          std::cout << "mousemotion over \"selected\" area" << std::endl;
        }
        break;
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x, &y);
        if (isInside(x, y, &button)) {
          std::cout << "mouse button down on \"selected\" area" << std::endl;
        }
        break;
      case SDL_MOUSEBUTTONUP:
        SDL_GetMouseState(&x, &y);
        if (isInside(x, y, &button)) {
          std::cout << "mouse button up from \"selected\" area" << std::endl;
        }
        break;
      } //endof switch case
    } // endof while sdl_pollevent
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture,NULL, &button);
    SDL_RenderPresent(renderer);
  } // endof while running  
  IMG_Quit();
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
