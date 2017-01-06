#include "GameEngine.h"

GameEngine::GameEngine(Game* g, unsigned int screen_width, unsigned int screen_height) {
  cliens = new Client();
  context = new GameContext(screen_width, screen_height);
  game = g;
  game->init(*context);
  otherXCord = -1;
  otherYCord = -1;
}

void GameEngine::run() {
  SDL_Event event;
  bool gameover = false;
  while (!gameover) {

    if (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        gameover = true;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_q:
          gameover = true;
          break;
        }
      case SDL_MOUSEBUTTONDOWN:
        int x = 0, y = 0;
        SDL_GetMouseState(&x, &y);
        game->makeStep(x, y);
        cliens->cs->sendCoordinates(x, y);
        cliens->cs->checkForIncomingMessages();
        if (cliens->cs->gotMessage) {
          cout << "here" << endl;
          cliens->waitForTheFuckingMiracle();
          getOtherPlayerCoordinates(cliens->receivedMessage);
          game->makeStep(otherXCord, otherYCord);
        }        
        break;
      }
    }
    game->render(*context);
  }
}

void GameEngine::getOtherPlayerCoordinates(char* message) {
  otherXCord = (int)message[0];
  otherYCord = (int)message[1];
}

GameEngine::~GameEngine() {
  delete context;
  delete cliens;
}