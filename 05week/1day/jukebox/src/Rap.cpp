#include "Rap.h"

using namespace std;

Rap::Rap(string title, string artist) : Song::Song(title, artist) {
  this->setGenre("RAP");
}

void Rap::setRating(unsigned int rating) {
  if (rating < 1 || rating > 5) {
    cerr << "false ratification" << endl;
    return;
  }
  this->rating += rating;
  this->rateCounter++;
}

Rap::~Rap() {}
