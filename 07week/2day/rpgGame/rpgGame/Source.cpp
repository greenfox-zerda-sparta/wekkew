#include "game-engine.h"
#include "MyGame.h"

using namespace std;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  MyGame game = MyGame();
  GameEngine engine(&game, 920, 720);
  engine.run();

  return 0;
}