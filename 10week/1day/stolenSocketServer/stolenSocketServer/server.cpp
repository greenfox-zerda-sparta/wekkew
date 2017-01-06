// Re-written simple SDL_net socket server example | Nov 2011 | r3dux
// Library dependencies: libSDL, libSDL_net

#include "ServerSocket.h"

int main(int argc, char *argv[]) {
  SDLNet_Init();
  ServerSocket* ss;
  ss = new ServerSocket(1234, 16, 5);
	int activeClient = -1;
	do {
		ss->checkForConnections();
		do {
			activeClient = ss->checkForActivity();
			if (activeClient != -1) {
				ss->dealWithActivity(activeClient);
			}
		} while (activeClient != -1);
	} while (ss->getShutdownStatus() == false);
	SDLNet_Quit();
	return 0;
}