#include "Pop.h"
#include "Song.h"

Pop::Pop(string title, string artist) : Song::Song(title, artist) {
  this->genre = "POP";
}

void Pop::rate(unsigned int rating) {
  if (rating < 1 || rating > 5) {
    return;
  }
  this->setRating(rating);
}

Pop::~Pop() {

}
