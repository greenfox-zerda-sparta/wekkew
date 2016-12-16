#include <iostream>
#include <SDL.h>
#include "draw.h"
#include <cmath>

using namespace std;

void drawLineXlong(SDL_Renderer* renderer, draw& d, int length) {
  d.DrawBy(renderer, length);
}

void drawSixAngles(SDL_Renderer* renderer,int startX, int startY, int size) {
  if (size <= 0) {
    return;
  }
  draw d;
  int x = 0;
  int y = 0;
  d.MoveTo(startX, startY);
  for (int i = 0; i < 6; i++) {
    drawLineXlong(renderer, d, size);
    d.TurnBy(60);
    if (i == 1) {
      x = d.getX();
      y = d.getY();
    }
  }

  int halfHeigth = sqrt(3)/2 * size;
  drawSixAngles(renderer, startX, startY, size / 2);
  drawSixAngles(renderer, startX, startY + halfHeigth , size / 2);
  drawSixAngles(renderer, x - halfHeigth + size / 10 + 1, y - halfHeigth / 2 , size / 2);

}

int main(int argc, char ** argv) {

  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("13 Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
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
    draw d;
    drawSixAngles(renderer, 150, 50, 300); //startx starty size
    //SDL_RenderPresent(renderer);

  }
  SDL_RenderPresent(renderer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}