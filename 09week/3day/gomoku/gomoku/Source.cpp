#include "MyGame.h"
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {

  MyGame game = MyGame();
  GameEngine engine(&game, 200, 200);
  engine.run();

  system("pause");
  return 0;
}