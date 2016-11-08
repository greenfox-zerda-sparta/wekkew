#ifndef PIRATE_H_
#define PIRATE_H_

namespace std {

class Pirate {
public:
  Pirate();
  void drinkRun();
  void howsGoingMate();
  virtual ~Pirate();
private:
  int drinkCount;
};

} /* namespace std */

#endif /* PIRATE_H_ */
