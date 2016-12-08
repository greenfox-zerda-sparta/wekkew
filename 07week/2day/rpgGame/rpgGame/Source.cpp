#include "game-engine.h"
#include "MyGame.h"
#include "TableGenerator.h"

using namespace std;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  MyGame game = MyGame();
  for (int i = 0; i < game.levelTable.size(); i++) {
    for (int j = 0; j < game.levelTable[i].size(); j++) {
      cout << game.levelTable[i][j] << " ";
    }
    cout << endl;
  }
  GameEngine engine(&game, 720, 720);
  engine.run();

  return 0;
}