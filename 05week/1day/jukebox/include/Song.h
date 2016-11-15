#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {
  private:
    string title;
    string artist;
    string genre;
  protected:
    unsigned int rating;
    unsigned int rateCounter;
  public:
    Song(string, string);
    void setGenre(string);
    double getAverageRating();
    string getEverything();
    virtual void setRating(unsigned int) = 0;
    string getTitle();
    string getArtist();
    string getGenre();
    virtual ~Song();
};

#endif // SONG_H
