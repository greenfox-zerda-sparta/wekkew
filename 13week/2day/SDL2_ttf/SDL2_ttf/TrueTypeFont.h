#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class TrueTypeFont {
private:
  int rectXCord = 0;
  int rectYCord = 0;
  std::string fontName;
  std::string text = "Hello, World!";
  int fontSize = 40;
  TTF_Font* font = NULL;
  SDL_Color textColor;
  //SDL_Color backgroundColor;
  SDL_Texture* solidTexture = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Rect solidRect;
public:
  TrueTypeFont(std::string, SDL_Renderer*);
  void setFontSize(int);
  void setText(std::string);
  void render();
  std::string getText();
  int getXCord();
  int getYCord();
  void setCordinates(int, int);
  void setFontType(std::string);
  void setTextColor(Uint8, Uint8, Uint8, Uint8);
  //void setBackgroundColor(Uint8, Uint8, Uint8, Uint8);
  ~TrueTypeFont();
private:
  void setFont();
  void setTextColor();
  //void setBackgroundColor();
  void createTextTexture();
  SDL_Texture* SurfaceToTexture(SDL_Surface*);
};

