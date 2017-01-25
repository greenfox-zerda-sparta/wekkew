#include "TrueTypeFont.h"
#include <iostream>

TrueTypeFont* InitEverything();
void Render();
void ttfInitialise();

//SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
//TTF_Font* font;
//SDL_Color textColor = { 255, 255, 255, 255 }; // white
//SDL_Color backgroundColor = { 0, 0, 0, 255 }; // black
//SDL_Texture* solidTexture;
//SDL_Rect solidRect;
SDL_Rect windowRect = { 0, 30, 640, 480 };
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* args[]) {
  TrueTypeFont* apple = InitEverything();
  std::cout << apple->getText() << std::endl;
  apple->setText("lazy fox jumps ofer the quick dog");
  std::cout << apple->getText() << std::endl;
  apple->setFontsize(40);
  SDL_Event event;
  bool running = true;
  while (running) {

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }
    apple->render();
  }

  //TTF_CloseFont(font);
  return 0;
}


void Render() {
  SDL_RenderClear(renderer);
 // SDL_RenderCopy(renderer, solidTexture, NULL, &solidRect);
  SDL_RenderPresent(renderer);
}

/*
void CreateTextTextures(std::string name) {
  SDL_Surface* solid = TTF_RenderText_Solid(font, name.c_str(), textColor);
  solidTexture = SurfaceToTexture(solid);
  SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
  solidRect.x = 0;
  solidRect.y = 0;
}
// Convert an SDL_Surface to SDL_Texture. We've done this before, so I'll keep it short
SDL_Texture* SurfaceToTexture(SDL_Surface* surf) {
  SDL_Texture* text;
  text = SDL_CreateTextureFromSurface(renderer, surf);
  SDL_FreeSurface(surf);
  return text;
}
*/

TrueTypeFont* InitEverything() {
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("TextToFont", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  // Set size of renderer to the same as window 
  SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);
  // ttfInitialise();
  TrueTypeFont* apple = new TrueTypeFont("Arial.ttf", renderer);
  return apple;
}

void ttfInitialise() {
  TTF_Init();
  const std::string fontName = "Arial.ttf";
//  font = TTF_OpenFont(fontName.c_str(), 40); // font type , font size
  //CreateTextTextures("ide beirhatok akarmit");
}