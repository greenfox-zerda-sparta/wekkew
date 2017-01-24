#include "LButton.h"


LButton::LButton() {
  mPosition.x = 0;
  mPosition.y = 0;
  mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition(int x, int y) {
  mPosition.x = x;
  mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* event) {
  if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool inside = true;
    if (x < mPosition.x) {
      inside = false;
    }
    else if (x > mPosition.x + BUTTON_WIDTH) {
      inside = false;
    }
    else if (y < mPosition.y) {
      inside = false;
    }
    else if (y > mPosition.y + BUTTON_HEIGHT) {
      inside = false;
    }

    if (!inside) {
      mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    }
    else {
      switch (event->type) {
      case SDL_MOUSEMOTION:
        mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
        break;
      case SDL_MOUSEBUTTONDOWN:
        mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
        break;
      case SDL_MOUSEBUTTONUP:
        mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
        break;
      }
    }
  }
}

void LButton::render(LTexture* texture, SDL_Rect* rect) {
  this->texture = texture;
  this->spriteRect = rect;
  texture->render(mPosition.x, mPosition.y, &spriteRect[mCurrentSprite]);
}
