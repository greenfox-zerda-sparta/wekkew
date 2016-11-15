#ifndef RAP_H
#define RAP_H

#include <Song.h>

class Rap : public Song {
  public:
    Rap(string, string);
    void setRating(unsigned int);
    virtual ~Rap();
};

#endif // RAP_H
