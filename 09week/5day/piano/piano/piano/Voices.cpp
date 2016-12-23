#include "Voices.h"

using namespace std;

Voices::Voices() {
  fillSounds();
  duration = 500;
}

void Voices::fillSounds() {
  sounds[99] = 261.63;
  sounds[100] = 293.66;
  sounds[101] = 329.63;
  sounds[102] = 349.23;
  sounds[103] = 392;
  sounds[97] = 440;
  sounds[104] = 493.88;
  sounds[1073742049] = 523.25;
}

void Voices::playSound(int keyCode) {
  Beep(sounds[keyCode], duration);
}

Voices::~Voices() {
}
