#include "Jukebox.h"

Jukebox::Jukebox() {
  this->songCounter = 0;
  this->songs = NULL;
}

void Jukebox::addToJB(Song& song) {
  Song** temp = new Song*[songCounter+1];
  for (int i = 0; i < songCounter; i++) {
    temp[i] = songs[i];
  }
  temp[songCounter] = &song;
  delete[] this->songs;
  this->songs = temp;
  this->songCounter++;
}

Jukebox::~Jukebox() {
  delete[] this->songs;
}
