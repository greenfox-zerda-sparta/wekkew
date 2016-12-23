#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")


class Player {
private:
  LPCSTR path;
public:
  Player(LPCSTR);
  void play();
  ~Player();
};

