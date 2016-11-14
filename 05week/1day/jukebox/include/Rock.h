#ifndef ROCK_H
#define ROCK_H

#include <Song.h>
#include <string>


class Rock : public Song {
  public:
    Rock(string, string);
    void setRating(unsigned int);
  virtual ~Rock();
};

#endif // ROCK_H
