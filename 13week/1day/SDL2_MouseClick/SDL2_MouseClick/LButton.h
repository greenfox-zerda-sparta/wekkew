#pragma once
#include "LTexture.h"

enum LButtonSprite {
  BUTTON_SPRITE_MOUSE_OUT = 0,
  BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
  BUTTON_SPRITE_MOUSE_DOWN = 2,
  BUTTON_SPRITE_MOUSE_UP = 3,
  BUTTON_SPRITE_TOTAL = 4
};


const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

class LButton {
public:
  LButton();
  void setPosition(int, int);
  void handleEvent(SDL_Event*);
  void render(LTexture*, SDL_Rect*);
  ~LButton();
private:
  SDL_Point mPosition;
  LButtonSprite mCurrentSprite;
  LTexture* texture;
  SDL_Rect* spriteRect;
  bool isInside(int, int);
};