#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Player {
private:
  Mix_Music* music;
  string path;
  int delay;
public:
  Player();
  void play();
  void play(int);
  ~Player();
private:
  void getDelay();
  void getPath();
  void startSleep();
};