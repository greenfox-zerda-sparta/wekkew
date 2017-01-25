#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class TrueTypeFont {
private:
  std::string fontName;
  std::string text = "Hello, World!";
  int fontSize = 40;
  TTF_Font* font;
  SDL_Color textColor;
  SDL_Color backgroundColor;
  SDL_Texture* solidTexture;
  SDL_Renderer* renderer;
  SDL_Rect solidRect;
public:
  TrueTypeFont(std::string, SDL_Renderer*);
  ~TrueTypeFont();
  void setFontsize(int);
  void setText(std::string);
  void render();
  std::string getText();
//  void setFont(std::string);
//  void setTextColor(Uint8, Uint8, Uint8, Uint8);
//  void setBackgroundColor(Uint8, Uint8, Uint8, Uint8);
private:
  void setFont();
  void setTextColor();
  void setBackgroundColor();
  void createTextTexture();
  SDL_Texture* SurfaceToTexture(SDL_Surface*);
};

