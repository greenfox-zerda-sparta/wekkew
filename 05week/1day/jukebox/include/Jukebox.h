#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Song.h"

class Jukebox {
  public: //just for demonstration purpose
    Song** songs;
    unsigned int songCounter;
  public:
    Jukebox();
    void addToJB(Song& song);
    void rateSong(Song& song, unsigned int rate);
    virtual ~Jukebox();
};

#endif // JUKEBOX_H
