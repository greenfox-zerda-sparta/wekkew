#include <iostream>
#include <SDL.h>
#include "draw.h"

using namespace std;

void drawLine() {

}

void drawTriangle(SDL_Renderer* renderer,int startX, int startY, int size) {
  if (size <= 0) {
    return;
  }
  draw d;
  d.MoveTo(startX, startY);
 
  for (int i = 0; i < 3; i++) {
    d.DrawBy(renderer, size );
    d.TurnTo(120);
  }
  drawTriangle(renderer, startX + size / 2, startY, size / 2);
  drawTriangle(renderer, startX, startY, size / 2);
  drawTriangle(renderer, size / 4 + startX, startY + size / 2 - size/10, size / 2);


 
}

int main(int argc, char ** argv) {
  int line = 799; // ez nekem kell a rajzoláshoz, alapból nem kell
  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("Triangle Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 19, 19, 70, 0); // háttér színe
  SDL_RenderClear(renderer);

  while (!quit) {
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT) {
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // rajzolás színe
    
    drawTriangle(renderer,0, 0, 590); // és ez az, amivel rajzolsz
    SDL_RenderPresent(renderer);

  }
  SDL_RenderPresent(renderer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}