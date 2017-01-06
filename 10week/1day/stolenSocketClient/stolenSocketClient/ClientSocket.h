#pragma once

#include <iostream>
#include <sstream>
#include <conio.h>           // Needed for kbhit and getch
#include "SDL_net.h"         // Include SDL_net, which includes SDL.h for us

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class ClientSocket {
private:
	unsigned int serverPort;    // The port of the server to connect to
	unsigned int bufferSize;    // The size of our message buffer
	string    serverHostname;   // The host name of the server (i.e. "localhost", "www.foo.com" etc.
	IPaddress serverIP;         // The IP address of the server to connect to (NOT in dot-quad format)
	string    dotQuadString;    // The IP address of the server to connect to as a dot-quad (i.e. 127.0.0.1)
	TCPsocket serverSocket;     // The server socket
	TCPsocket clientSocket;     // Our own client socket
	char* pBuffer;            // A pointer to (what will be) an array of characters used to store the messages we send and receive
	string  userInput;          // User input string
	int     inputLength;        // The length of our userInput in characters
  SDLNet_SocketSet socketSet; // Our entire set of sockets (i.e. just the server socket and our client socket)
  bool shutdownClient;        // Flag to control when to shut down the client
public:
	static const string SERVER_NOT_FULL;
	static const string SERVER_FULL;
	static const string SHUTDOWN_SIGNAL;
	static const string QUIT_SIGNAL;
	static const unsigned int CONNECTION_TIMEOUT_PERIOD;
	static const unsigned int SOCKET_SET_POLL_PERIOD;
  ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize);
  ~ClientSocket();
	void connectToServer();
	string checkForIncomingMessages();
	void sendCoordinates(int, int);
	void displayPrompt();
	void getUserInput();
	string getCurrentUserInputContents();
	bool getShutdownStatus();
};

template<class T>
string toString(const T& t) {
	std::ostringstream stream;
	stream << t;
	return stream.str();
}