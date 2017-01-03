#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();

  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  cout << ip.host << " | " << ip.port << endl;
  
  string text;
  string welcomeText = "\"exit\" closes the server \n\"quit\" closes the client \nEnter the message:";
  
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
	  cout << welcomeText << endl;
	  while (1) {
		getline(cin, text);
		if (text == "exit") {
			break;
		}
		else {
			SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
		}
	  }
	  SDLNet_TCP_Close(client);
      break;
    }
  }
  SDL_Quit();
  return 0;
}