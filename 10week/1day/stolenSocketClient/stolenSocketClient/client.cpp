// Re-written simple SDL_net socket client example | Nov 2011 | r3dux
// Library dependencies: libSDL, libSDL_net

#include <iostream>
#include <string>
#include <SDL_net.h>
#include "ClientSocket.h"

using std::cerr;
using std::endl;
using std::string;
using std::cin;
using std::getline;

void getIPandPort(string&, int&);

int main(int argc, char* argv[]) {
  SDLNet_Init();
	ClientSocket* cs;
  
  string ipAdress;
  int port;
  getIPandPort(ipAdress, port);

  cs = new ClientSocket(ipAdress, port, 512);
	cs->connectToServer();
  string receivedMessage = "";
	cs->displayPrompt();
	do {
		receivedMessage = cs->checkForIncomingMessages();
    if (receivedMessage != "") { //ez a resz majd geci felesleges lesz ha a Gomoku Controller adja az inputot
			cs->displayPrompt();
		}
		cs->getUserInput();
	} while ((cs->getShutdownStatus() == false));

	SDLNet_Quit();
	return 0;
}

void getIPandPort(string& ipAdress, int& port) {
  cout << "Enter IP adress of server \nif empty then defult: 127.0.0.1" << endl;
  getline(cin, ipAdress);
  if (ipAdress == "") {
    ipAdress = "127.0.0.1";
  }
  cout << "Enter port number of server\nif 0 then default: 1234" << endl;
  cin >> port;
  if (port == 0) {
    port = 1234;
  }
}