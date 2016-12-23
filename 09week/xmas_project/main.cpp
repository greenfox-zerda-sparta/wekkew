#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void getTime(time_t& now) {
  cout << "gettime";
  now = time(0);
  getTime(now);
}

main (int argc, char* argv[]) {
    
  time_t now = time(0);
  string dt = ctime(&now);
  time_t tenSecLater = time(0) + 10;
  
  
  if (getTime(now) == tenSecLater) {
    cout << "Merry xmas" << endl;
  }
/*#include <time.h>

clock_t init, final;

init=clock();
//
// do stuff
//
final=clock()-init;
cout << (double)final / ((double)CLOCKS_PER_SEC);
*/
  return 0;
}
