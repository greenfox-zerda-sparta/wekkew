#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

class LTexture {
public:
  LTexture();
  ~LTexture();
  bool loadFromFile(std::string path, SDL_Renderer* renderer);
  void free();
  void setColor(Uint8 red, Uint8 green, Uint8 blue);
  void setBlendMode(SDL_BlendMode blending);
  void setAlpha(Uint8 alpha);
  void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
  int getWidth();
  int getHeight();
private:
  //The actual hardware texture
  SDL_Texture* mTexture;
  SDL_Renderer* mRenderer;

  //Image dimensions
  int mWidth;
  int mHeight;
};