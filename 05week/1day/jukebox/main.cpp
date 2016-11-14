#include <iostream>
#include "Pop.h"
#include "Rock.h"
#include "Reggie.h"
#include "Jukebox.h"

using namespace std;

int main() {
  Jukebox juuk;
  Pop hello("hello", "adele");
    hello.setRating(4);
  Pop friday("friday", "adele");
    friday.setRating(2);
  Rock tnt("tnt", "adele");
  Pop pra("Party Rock Anthem", "LMFAO");
    pra.setRating(2);
  Rock rumine("R U Mine", "Artic Monkeys");
    rumine.setRating(5);
  Reggie nwnc("No C++ No Cry", "Bob Marley");
    nwnc.setRating(1);
  Rock chop("Chop Suey", "SOAD");
  chop.setRating(4);

  juuk.addToJB(chop);
  juuk.addToJB(nwnc);
  juuk.addToJB(rumine);
  juuk.addToJB(pra);
  juuk.addToJB(hello);
  juuk.addToJB(friday);
  juuk.addToJB(tnt);
  juuk.rateSong(tnt, 5);
  cout << juuk.artistRate("adele") << endl;
  cout << juuk.genreRate("POP") << endl;
  cout << juuk.topRated() << endl;
  cout << juuk.topRatedGenre() << endl;

  return 0;
}
