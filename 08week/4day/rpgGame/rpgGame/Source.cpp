#include <SDL.h>
#include "draw.h"

using namespace std;

void drawNineSquares(SDL_Renderer* renderer, int x, int y, int xNull, int yNull) {
  if (x > 2) {
    draw d;
    //first vertical line
    d.MoveTo(xNull + x / 3, yNull);
    d.DrawTo(renderer, xNull + x / 3, yNull + y);
    //second vertical line
    d.MoveTo(xNull + 2 * x / 3, yNull);
    d.DrawTo(renderer, xNull + 2 * x / 3, yNull + y);
    //upper horizontal line
    d.MoveTo(xNull, yNull + y / 3);
    d.DrawTo(renderer, xNull + x, yNull + y / 3);
    //downer horizontal line
    d.MoveTo(xNull, yNull + 2 * y / 3);
    d.DrawTo(renderer,xNull + x, yNull + 2 * y / 3);

    //recursive call for the inner square drawing:
    // first line second square
    drawNineSquares(renderer, x / 3, y / 3, xNull + x / 3, yNull); 
    // second linde first square
    drawNineSquares(renderer, x / 3, y / 3, xNull, yNull +  y / 3); 
    // second line third square
    drawNineSquares(renderer, x / 3, y / 3, xNull + 2 * x / 3, yNull + y /3); 
    // third line second square
    drawNineSquares(renderer, x / 3, y / 3, xNull + x / 3, yNull + 2 * y / 3); 
  }
}

int main(int argc, char* argv[]) {

  bool quit = false;
  
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  
  SDL_Window* window = SDL_CreateWindow("11 Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  while (!quit) {
    SDL_WaitEvent(&event);
    
    switch (event.type) {
      case SDL_QUIT:
        quit = true;
        break;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    drawNineSquares(renderer, 600, 600, 0, 0);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  
  return 0;
}