#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Song.h"

class Jukebox {
  private:
    Song** songs;
    unsigned int songCounter;
  public:
    Jukebox();
    void addToJB(Song& song);
    virtual ~Jukebox();
};

#endif // JUKEBOX_H
