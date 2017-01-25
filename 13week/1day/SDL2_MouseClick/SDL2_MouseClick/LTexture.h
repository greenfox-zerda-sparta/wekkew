#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

class LTexture {
public:
  LTexture();
  ~LTexture();
  bool loadFromFile(std::string path, SDL_Renderer* renderer);
  void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
  int getWidth();
  int getHeight();
private:
  SDL_Texture* mTexture;
  SDL_Renderer* mRenderer;
  int mWidth;
  int mHeight;
};