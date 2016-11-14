#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

Song::Song(string title, string artist) {
  this->artist = artist;
  this->title = title;
  this->rating = 0;
  this->rateCounter = 0;
}

void Song::setGenre(string genre) {
  this->genre = genre;
}

string Song::getEverything() {
  return "Artist: " + this->artist + ", Title: " + this->title + ", Genre: " + this->genre + ".";
}

double Song::getAverageRating() {
  return rating/(float)rateCounter;
}

string Song::getTitle() {
  return this->title;
}
string Song::getArtist() {
  return this->artist;
}
string Song::getGenre() {
  return this->genre;
}

Song::~Song() {

}
