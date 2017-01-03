#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

bool isQuit(char*);

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();

  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  std::cout << int(ip.host) << " | " << int(ip.port) << std::endl;

  char text[100];
  while (1) {
	  SDLNet_TCP_Recv(client, text, 100);
	  if (isQuit(text)) {
		  break;
	  }
	  else {
		  std::cout << text << std::endl;
	  }
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}

bool isQuit(char* text) {
	const char* quit = "quit";
	for (int i = 0; i < 4; i++) {
		if (quit[i] != text[i]) {
			return false;
		}
	}
	return true;
}