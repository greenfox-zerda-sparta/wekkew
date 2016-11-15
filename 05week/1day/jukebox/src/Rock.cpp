#include "Rock.h"
#include <iostream>

using namespace std;

Rock::Rock(string title, string artist) : Song::Song(title, artist) {
  this->setGenre("ROCK");
}

void Rock::setRating(unsigned int rating) {
  if (rating < 2 || rating > 5) {
    cerr << "false ratification" << endl;
    return;
  }
  this->rating += rating;
  this->rateCounter++;
}

Rock::~Rock() {}
