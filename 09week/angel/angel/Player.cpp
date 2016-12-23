#include "Player.h"

using namespace std;

Player::Player() {
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 3072);
  music = NULL;
  getPath();
  getDelay();
  music = Mix_LoadMUS(path.c_str());
}

void Player::getPath() {
  cout << "Enter the exact name and extension of the file you want to play:" << endl;
  getline(cin, this->path);
}

void Player::play() {
  startSleep();
  Mix_PlayMusic(music, 1);
  cout << "I'm playing: " << path << " ..." << endl;
}

void Player::play(int loopNumber) {
  startSleep();
  Mix_PlayMusic(music, loopNumber);
  cout << "I'm playing: " << path << " ..." << endl << loopNumber << " times" << endl;
}

void Player::startSleep() {
  Sleep(this->delay * 1000);
}

void Player::getDelay() {
  string delay;
  cout << "Enter the delay time (seconds) :" << endl;
  getline(cin, delay);
  this->delay = atoi(delay.c_str());
}

Player::~Player() {
  Mix_FreeMusic(music);
  Mix_CloseAudio();
}
