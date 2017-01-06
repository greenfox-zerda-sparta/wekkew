#define _CRT_SECURE_NO_WARNINGS
#include "ClientSocket.h"

const string  ClientSocket::SERVER_NOT_FULL = "OK";                 // Server's response when there are free spots a client can join
const string  ClientSocket::SERVER_FULL = "FULL";                   // Server's response when there are no free spots, so a client cannot join
const string  ClientSocket::SHUTDOWN_SIGNAL = "/shutdown";          // What you type to shutdown the server
const string  ClientSocket::QUIT_SIGNAL = "/quit";                  // What you type to shutdown the client
const unsigned int ClientSocket::CONNECTION_TIMEOUT_PERIOD = 5000;  // 5 second connection timeout
const unsigned int ClientSocket::SOCKET_SET_POLL_PERIOD = 10;       // 10ms, so poll 100 times/second

ClientSocket::ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize) {
	shutdownClient = false;
	serverHostname = theServerAddress;
  serverPort = theServerPort;
	bufferSize = theBufferSize;
	inputLength = 0;
	pBuffer = new char[bufferSize];
  socketSet = SDLNet_AllocSocketSet(2);
}

ClientSocket::~ClientSocket() {
	SDLNet_TCP_Close(serverSocket);
	SDLNet_TCP_Close(clientSocket);
	SDLNet_FreeSocketSet(socketSet);
	delete pBuffer;
}

void ClientSocket::connectToServer() {
	int hostResolved = SDLNet_ResolveHost(&serverIP, serverHostname.c_str(), serverPort);
	Uint8 * dotQuad = (Uint8*)&serverIP.host;
	dotQuadString = toString((unsigned short)dotQuad[0]);
	dotQuadString += ".";
	dotQuadString += toString((unsigned short)dotQuad[1]);
	dotQuadString += ".";
	dotQuadString += toString((unsigned short)dotQuad[2]);
	dotQuadString += ".";
	dotQuadString += toString((unsigned short)dotQuad[3]);

	clientSocket = SDLNet_TCP_Open(&serverIP);

	SDLNet_TCP_AddSocket(socketSet, clientSocket);
	int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::CONNECTION_TIMEOUT_PERIOD);
	int gotServerResponse = SDLNet_SocketReady(clientSocket);
  if (gotServerResponse != 0) {
    SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);
    string bufferContents = pBuffer;
    cout << "msg from server(pBuffer) " << pBuffer << endl;
  }
}

string ClientSocket::checkForIncomingMessages() {
	string receivedMessage = "";
	int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::SOCKET_SET_POLL_PERIOD);
	if (activeSockets != 0) {
    if (SDLNet_SocketReady(clientSocket) != 0) {
      int serverResponseByteCount = SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);
      cout << endl << "message: " << pBuffer << endl;
      if (serverResponseByteCount != 0) {
        receivedMessage = toString(pBuffer);
        if (receivedMessage == ClientSocket::SHUTDOWN_SIGNAL) {
          shutdownClient = true;
        }
      }
    }
	}
	return receivedMessage;
}

void ClientSocket::sendCoordinates(int yCord, int xCord) {
  string util = toString(yCord) + "," + toString(xCord);
  const char* message = util.c_str();
  SDLNet_TCP_Send(clientSocket, (void *)message, strlen(message) +1);
}

void ClientSocket::displayPrompt() {
	cout << "Write something >>> " << getCurrentUserInputContents();
	fflush(stdout);
}

void ClientSocket::getUserInput() {
	int status = _kbhit();
	if (status != 0) {
		char theChar = _getch();
		cout << theChar;
		fflush(stdout);
		if ((int)theChar != 13) {
			userInput += theChar;
		}
		else {
			strcpy(pBuffer, userInput.c_str());
      inputLength = strlen(pBuffer) + 1;
			if (userInput != ClientSocket::QUIT_SIGNAL) {
        SDLNet_TCP_Send(clientSocket, (void *)pBuffer, inputLength);
			  cout << endl;
			  cout << "Write something >>> ";
			  fflush(stdout);
			  userInput = "";
			}
			else {
				shutdownClient = true;
			}
		}
	}
}

string ClientSocket::getCurrentUserInputContents() {
	return userInput;
}

bool ClientSocket::getShutdownStatus() {
	return shutdownClient;
}