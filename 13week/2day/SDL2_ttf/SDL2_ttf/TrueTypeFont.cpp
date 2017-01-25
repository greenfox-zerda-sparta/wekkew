#include "TrueTypeFont.h"

TrueTypeFont::TrueTypeFont(std::string fontName, SDL_Renderer* renderer) {
  this->fontName = fontName;
  this->renderer = renderer;
  TTF_Init();
  setFont();
  setTextColor();
  setBackgroundColor();
}

void TrueTypeFont::setFont() {
  font = TTF_OpenFont(fontName.c_str(), fontSize);
}

void TrueTypeFont::setFontsize(int newSize) {
  this->fontSize = newSize;
}

void TrueTypeFont::setText(std::string text) {
  this->text = text;
}

void TrueTypeFont::createTextTexture() {
  SDL_Surface* solid = TTF_RenderText_Solid(font, text.c_str(), textColor);
  solidTexture = SurfaceToTexture(solid);
  SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = 0;
  solidRect.y = 0;
}

void TrueTypeFont::setTextColor() {
  textColor = { 255, 255, 255, 255 };
}

void TrueTypeFont::setBackgroundColor() {
  backgroundColor = { 0, 0, 0, 255 };
}

SDL_Texture* TrueTypeFont::SurfaceToTexture(SDL_Surface* surf) {
  SDL_Texture* text;
  text = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_FreeSurface(surf);
  return text;
}

std::string TrueTypeFont::getText() {
  return this->text;
}

/*void TrueTypeFont::setFont(std::string newFontName) {
  this->fontName = newFontName;
  setFont();
}
void TrueTypeFont::setTextColor(Uint8 newRed, Uint8 newGreen, Uint8 newBlue, Uint8 newAlpha) {
  this->textColor = { newRed, newGreen, newBlue, newAlpha};
}
void TrueTypeFont::setBackgroundColor(Uint8 newRed, Uint8 newGreen, Uint8 newBlue, Uint8 newAlpha) {
 this->backgroundColor = { newRed, newGreen, newBlue, newAlpha };
}*/

void TrueTypeFont::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
  SDL_RenderPresent(renderer);
}

TrueTypeFont::~TrueTypeFont() {
  TTF_CloseFont(font);
}