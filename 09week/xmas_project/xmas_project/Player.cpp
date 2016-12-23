#include "Player.h"

using namespace std;

Player::Player(LPCSTR path) {
  this->path = path;
}

void Player::play() {
  PlaySound(path, NULL, SND_FILENAME);
}

Player::~Player() {
}
