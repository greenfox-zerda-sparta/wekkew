#include "Rock.h"
#include <iostream>

using namespace std;

Rock::Rock(string title, string artist) : Song::Song(title, artist) {
  this->genre = "ROCK";
}

void Rock::rate(unsigned int rating) {
  if (rating < 2 || rating > 5) {
    cerr << "false ratification" << endl;
    return;
  }
  this->setRating(rating);
}

Rock::~Rock() {

}
