#include <iostream>
#include <string>
#include <Windows.h>
#include "ClientSocket.h"
#include "SDL_net.h"

int main(int argc, char *argv[]) {
	string *LocalIP = new string();
	*LocalIP = "10.27.99.165";

	SDLNet_Init(); 

	ClientSocket *cs;
	cs = new ClientSocket(*LocalIP, 1234, 512);
	cs->connectToServer();

	string receivedMessage = "";

	cs->displayPrompt();

	do {		
		receivedMessage = cs->checkForIncomingMessages();

		if (receivedMessage != "") {
			cs->displayMessage(receivedMessage);

			cs->displayPrompt();
		}

		cs->getUserInput();

	} while (true);

	SDLNet_Quit();
	delete LocalIP;

	return 0;
}
