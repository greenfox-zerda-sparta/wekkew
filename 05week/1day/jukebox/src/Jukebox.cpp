#include "Jukebox.h"

Jukebox::Jukebox() {
  this->songCounter = 0;
  this->songs = NULL;
}

void Jukebox::addToJB(Song& song) {
  Song** temp = new Song*[songCounter+1];
  for (unsigned int i = 0; i < songCounter; i++) {
    temp[i] = songs[i];
  }
  temp[songCounter] = &song;
  delete[] this->songs;
  this->songs = temp;
  this->songCounter++;
}

void Jukebox::rateSong(Song& song, unsigned int rate) {
  bool noSong = true;
  for (unsigned int i = 0; i < songCounter; i++) {
    if (songs[i] == &song) {
      songs[i]->setRating(rate);
      noSong = false;
      return;
    }
  }
  if (noSong) {
    cerr << "There is no such song" << endl;
  }
}

double Jukebox::artistRate(string artist) {
  bool noArtist = true;
  double sumRate = 0;
  unsigned int sumRateCounter = 0;
  for (unsigned int i = 0; i < songCounter; i++) {
    if (songs[i]->getArtist() == artist) {
      sumRate += songs[i]->getAverageRating();
      sumRateCounter++;
      noArtist = false;
    }
  }
  if (noArtist) {
    cerr << "No such Artist!" << endl;
    return -1;
  }
  return sumRate / sumRateCounter;
}

double Jukebox::genreRate(string genre) {
  bool noGenre = true;
  double sumRate = 0;
  unsigned int sumRateCounter = 0;
  for (unsigned int i = 0; i < songCounter; i++) {
    if (songs[i]->getGenre() == genre) {
      sumRate += songs[i]->getAverageRating();
      sumRateCounter++;
      noGenre = false;
    }
  }
  if (noGenre) {
    cerr << "No such Genre" << endl;
    return -1;
  }
  return sumRate / sumRateCounter;
}

string Jukebox::topRated() {
  if (songCounter == 0) {
    return "No songs";
  }
  double top = 0;
  unsigned int topIndex = -1;
  for (unsigned int i = 0; i < songCounter; i++) {
    if (songs[i]->getAverageRating() > top) {
      top = songs[i]->getAverageRating();
      topIndex = i;
    }
  }
  return songs[topIndex]->getTitle();
}

string Jukebox::topRatedGenre() {
  if (songCounter == 0) {
    return "No songs";
  }
  string topGenre = songs[0]->getGenre();
  for (unsigned int i = 1; i < songCounter; i++) {
    if (genreRate(songs[i]->getGenre()) > genreRate(topGenre)) {
      topGenre = songs[i]->getGenre();
    }
  }
  return topGenre;
}

Jukebox::~Jukebox() {
  delete[] this->songs;
}
