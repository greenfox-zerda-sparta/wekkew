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
    void rateSong(Song& song, unsigned int rate);
    double artistRate(string);
    double genreRate(string);
    string topRated();
    string topRatedGenre();
    virtual ~Jukebox();
};

#endif // JUKEBOX_H
