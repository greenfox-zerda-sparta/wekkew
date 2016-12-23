#include<iostream>
#include <conio.h>
#include <windows.h>
#include <map>
#include <SDL.h>
#include "Synthetisator.h"

using namespace std;

void writOutTheKEy(SDL_Event event) {
  cout << event.key.keysym.sym << endl;
}

int main(int argc, char* argv[]) {
  
  bool quit = false;
  SDL_Event event;

  Synthetisator szinti;
  

  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      szinti.manageEvent(event.key.keysym.sym);
    }
  }
  return 0;
}