#ifndef CAR_H_
#define CAR_H_

using namespace std;

class Car {
  public:
    Car(string type, unsigned int km);
    virtual ~Car();
    void runCar(unsigned int runKm);
    void printKm();
  private:
    string type;
    unsigned int km;
};

#endif
