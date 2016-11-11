#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

Song::Song(string title, string artist) {
  this->artist = artist;
  this->title = title;
  this->rating;
  this->rateCounter = 0;
}

void Song::setRating(unsigned int rating) {
  this->rating += rating;
  this->rateCounter++;
}

string Song::getEverything() {
  return "Artist: " + this->artist + ", Title: " + this->title + ", Genre: " + this->genre + ".";
}

unsigned int Song::getRating() {
  return this->rating;
}

Song::~Song()
{
  //dtor
}
