#pragma once
#include <SDL.h>

class Window {
private:
  bool quit;
  int width;
  int heigth;
public:
  Window();
  ~Window();
};

