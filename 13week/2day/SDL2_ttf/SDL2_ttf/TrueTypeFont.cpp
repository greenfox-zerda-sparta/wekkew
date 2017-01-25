#include "TrueTypeFont.h"

TrueTypeFont::TrueTypeFont(std::string fontName, SDL_Renderer* renderer) {
  this->fontName = fontName;
  this->renderer = renderer;
  if (this->renderer == NULL) {
    std::cout << "no renderer" << std::endl;
  }
  TTF_Init(); // the original sdl_ttf initialisation
  setFont(); 
  setTextColor();
  setBackgroundColor();
  createTextTexture();
}

void TrueTypeFont::setFont()  {
  font = TTF_OpenFont(fontName.c_str(), fontSize);
  createTextTexture();
}

void TrueTypeFont::setFontSize(int newSize) {
  this->fontSize = newSize;
  setFont();
  std::cout << "new font size: " << this->fontSize << std::endl;
}

void TrueTypeFont::setText(std::string text) {
  this->text = text;
  createTextTexture();
}

void TrueTypeFont::createTextTexture() {
  SDL_Surface* solid = TTF_RenderText_Blended(font, text.c_str(), textColor);
  solidTexture = SurfaceToTexture(solid);
  SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = rectXCord;
  solidRect.y = rectYCord;
}

void TrueTypeFont::setTextColor() {
  textColor = { 255, 255, 255, 155 }; //snow white
}

void TrueTypeFont::setBackgroundColor() {
  backgroundColor = { 255, 0, 0, 155 }; // nigga's blood
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

int TrueTypeFont::getXCord() {
  return this->rectXCord;
}

int TrueTypeFont::getYCord() {
  return this->rectYCord;
}

void TrueTypeFont::setCordinates(int newXCord, int newYCord) {
  this->rectXCord = newXCord;
  this->rectYCord = newYCord;
  createTextTexture();
}

void TrueTypeFont::setFontType(std::string newFontName) {
  this->fontName = newFontName;
  setFont();
}

void TrueTypeFont::setTextColor(Uint8 newRed, Uint8 newGreen, Uint8 newBlue, Uint8 newAlpha) {
  this->textColor = { newRed, newGreen, newBlue, newAlpha};
  createTextTexture();
}

void TrueTypeFont::setBackgroundColor(Uint8 newRed, Uint8 newGreen, Uint8 newBlue, Uint8 newAlpha) {
 this->backgroundColor = { newRed, newGreen, newBlue, newAlpha };
}

void TrueTypeFont::render() {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
  SDL_RenderPresent(renderer);
}

TrueTypeFont::~TrueTypeFont() {
  TTF_CloseFont(font);
}