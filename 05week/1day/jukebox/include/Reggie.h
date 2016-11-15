#ifndef REGGIE_H
#define REGGIE_H

#include <Song.h>
#include <iostream>

class Reggie : public Song {
  public:
    Reggie(string, string);
    void setRating(unsigned int);
  virtual ~Reggie();
};

#endif // REGGIE_H
