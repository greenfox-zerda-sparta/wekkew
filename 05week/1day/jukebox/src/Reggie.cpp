#include "Reggie.h"

Reggie::Reggie(string title, string artist) : Song::Song(title, artist) {
  this->setGenre("REGGIE");
}

void Reggie::setRating(unsigned int rating) {
  if (rating < 1 || rating > 4) {
    cerr << "false ratification" << endl;
    return;
  }
  this->rating += rating;
  this->rateCounter++;
}

Reggie::~Reggie() {}
