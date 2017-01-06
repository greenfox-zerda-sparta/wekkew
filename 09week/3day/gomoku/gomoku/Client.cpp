#include "Client.h"

Client::Client() {
  SDLNet_Init();
  getIPandPort();
  bufferSize = 16;
  cs = new ClientSocket(ipAdress, port, bufferSize);
  connectToServer();
  receivedMessage = nullptr;
}

void Client::getIPandPort() {
  cout << "Enter IP adress of server \nif 0 then defult: 127.0.0.1" << endl;
  string currentIp;
  cin >> currentIp;
//  getline(cin, currentIp);
  
  if (currentIp[0] == '0') {
    this->ipAdress = "127.0.0.1";
  }
  else {
    this->ipAdress = currentIp;
  }
  cout << "Enter port number of server\nif 0 then default: 1234" << endl;
  cin >> this->port;
  if (port == 0) {
    this->port = 1234;
  }
  cout << this->ipAdress << "|" << this->port << endl;
}

void Client::connectToServer() {
  cs->connectToServer();
}

void Client::waitForTheFuckingMiracle() {
  do {
    receivedMessage = cs->checkForIncomingMessages();
  } while ((cs->getShutdownStatus() == false));
}


Client::~Client() {
  delete cs;
  SDLNet_Quit();
}
