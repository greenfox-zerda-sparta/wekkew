#ifndef POP_H
#define POP_H

#include <Song.h>
#include <string>


class Pop : public Song {
  public:
    Pop(string, string);
    void setRating(unsigned int);
  virtual ~Pop();
};

#endif // POP_H
