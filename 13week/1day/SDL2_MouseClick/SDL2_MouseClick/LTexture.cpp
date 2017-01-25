#include "LTexture.h"

LTexture::LTexture() {
  mTexture = NULL;
  mWidth = 0;
  mHeight = 0;
}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* renderer) {
  mRenderer = renderer;
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
  newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;
  SDL_FreeSurface(loadedSurface);
  mTexture = newTexture;
  return mTexture != NULL;
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
  SDL_Rect renderQuad = { x, y, mWidth, mHeight };
  if (clip != NULL) {
    renderQuad.w = clip->w;
    renderQuad.h = clip->h;
  }
  SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth() {
  return mWidth;
}

int LTexture::getHeight() {
  return mHeight;
}

LTexture::~LTexture() {
  if (mTexture != NULL) {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
  }
}
