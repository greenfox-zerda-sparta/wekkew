#define _CRT_SECURE_NO_WARNINGS
#include "ClientSocket.h"

const string  ClientSocket::SHUTDOWN_SIGNAL = "/shutdown";          // What you type to shutdown the server
const string  ClientSocket::QUIT_SIGNAL = "/quit";                  // What you type to shutdown the client
const unsigned int ClientSocket::CONNECTION_TIMEOUT_PERIOD = 5000;  // 5 second connection timeout
const unsigned int ClientSocket::SOCKET_SET_POLL_PERIOD = 10;       // 10ms, so poll 100 times/second

ClientSocket::ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize) {
  shutdownClient = false;
  serverHostname = theServerAddress;
  serverPort = theServerPort;
  bufferSize = theBufferSize;
  pBuffer = new char[bufferSize];
  socketSet = SDLNet_AllocSocketSet(2);
  gotMessage = false;
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

char* ClientSocket::checkForIncomingMessages() {
  gotMessage = false;
  char* receivedMessage = nullptr;
  int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::SOCKET_SET_POLL_PERIOD);
  if (activeSockets != 0) {
    if (SDLNet_SocketReady(clientSocket) != 0) {
      cout << "kaptam valamit" << endl;
      if (SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize)) {
        cout << endl << "message: " << pBuffer << endl;
        receivedMessage = pBuffer;
        if (receivedMessage == ClientSocket::SHUTDOWN_SIGNAL) {
          shutdownClient = true;
        }
      }
      gotMessage = true;
    }
  }
  return receivedMessage;
}

void ClientSocket::sendCoordinates(int yCord, int xCord) {
  char msg[2];
  msg[0] = (char)yCord / 40;
  msg[1] = (char)xCord / 40;
  SDLNet_TCP_Send(clientSocket, (void*)msg, 2);
}

bool ClientSocket::getShutdownStatus() {
  return shutdownClient;
}