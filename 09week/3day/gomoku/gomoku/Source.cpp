#include "Controller.h"

using namespace std;

int main(int argc, char** argv) {
  Controller game;
  GameEngine engine(&game, 760, 760);
  engine.run();
  
  return 0;
}
