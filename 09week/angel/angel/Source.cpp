#include <Windows.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Player.h"
//#include "Window.h"

using namespace std;

int main(int argc, char* argv[]) {

  Player player;
  player.play();
  //player.play(2);
  getchar();
  return 0;
}