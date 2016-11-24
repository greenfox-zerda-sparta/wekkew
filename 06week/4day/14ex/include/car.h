#ifndef CAR_H
#define CAR_H
#include <string>
#include <stdlib.h>
#include <time.h>


using /*motherfucker*/ namespace std;

class car {
  public:
    car();
    string getData();
    virtual ~car();
  private:
    string type;
    string color;
    string plate;
};

#endif // CAR_H
