#include "Pop.h"
#include "Song.h"

Pop::Pop(string title, string artist) : Song::Song(title, artist) {
  this->setGenre("POP");
}

void Pop::setRating(unsigned int rating) {
    if (rating < 1 || rating > 5) {
    cerr << "false ratification" << endl;
    return;
  }
  this->rating += rating;
  this->rateCounter++;
}

Pop::~Pop() {}
