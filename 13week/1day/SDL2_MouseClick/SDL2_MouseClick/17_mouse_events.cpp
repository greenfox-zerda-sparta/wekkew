#include "LButton.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gButtonSpriteSheetTexture;
SDL_Rect gSpriteClips[BUTTON_SPRITE_TOTAL];
LButton gButtons[BUTTON_SPRITE_TOTAL];

void Init();
void LoadMedia();
void close();

int main(int argc, char* argv[]) {
  Init();
  LoadMedia();

  bool running = true;

  SDL_Event event;

  while (running) {

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          running = false;
          break;
        case SDLK_SPACE:
          std::cout << "SPACE bitches" << std::endl;
          break;
        }
      }
      for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
        gButtons[i].handleEvent(&event);
      }
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
      gButtons[i].render(&gButtonSpriteSheetTexture, gSpriteClips);
    }
    SDL_RenderPresent(gRenderer);
  }
  close();
  return 0;
}

void Init() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  gWindow = SDL_CreateWindow("SDL Mouse Bindzsi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
  IMG_Init(IMG_INIT_PNG);
}

void LoadMedia() {
  gButtonSpriteSheetTexture.loadFromFile("C:\\Users\\wekke\\Documents\\Greenfox\\wekkew\\13week\\1day\\SDL2_MouseClick\\SDL2_MouseClick\\button.png", gRenderer);
  for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
    gSpriteClips[i].x = 0;
    gSpriteClips[i].y = i * BUTTON_HEIGHT;
    gSpriteClips[i].w = BUTTON_WIDTH;
    gSpriteClips[i].h = BUTTON_HEIGHT;
  }
  gButtons[0].setPosition(0, 0);
  gButtons[1].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, 0);
  gButtons[2].setPosition(0, SCREEN_HEIGHT - BUTTON_HEIGHT);
  gButtons[3].setPosition(SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT);
}

void close() {
  gButtonSpriteSheetTexture.free();
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;
  IMG_Quit();
  SDL_Quit();
}