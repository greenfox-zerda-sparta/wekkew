#pragma once

#include <iostream>
#include <string>
#include <SDL_net.h>
#include "ClientSocket.h"

using std::string;
using std::getline;
using std::cin;

class Client {
public:
  ClientSocket* cs;
  string ipAdress;
  int port;
  int bufferSize;
  char* receivedMessage;
public:
  Client();
  ~Client();
  void getIPandPort();
  void connectToServer();
  void waitForTheFuckingMiracle();
};

