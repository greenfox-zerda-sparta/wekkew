#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {
  protected:
    string title;
    string artist;
    string genre;
    unsigned int rating;
    unsigned int rateCounter;
  public:
    Song(string, string);
    double getAverageRating();
    string getEverything();
    virtual ~Song();
  protected:
    void setRating(unsigned int);
};

#endif // SONG_H
