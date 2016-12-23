#include "Window.h"

using namespace std;

Window::Window() {
  quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("Angel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigth, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0); // háttér színe
  SDL_RenderClear(renderer);
}


Window::~Window() {
}
