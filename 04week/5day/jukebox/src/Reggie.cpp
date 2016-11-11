#include "Reggie.h"

Reggie::Reggie(string title, string artist) : Song::Song(title, artist) {
  this->genre = "REGGIE";
}

void Reggie::rate(unsigned int rating) {
  if (rating < 1 || rating > 4) {
    return;
  }
  this->setRating(rating);
}

Reggie::~Reggie() {
  //dtor
}
