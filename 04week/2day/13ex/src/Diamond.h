/*
 * Diamond.h
 *
 *  Created on: 2016. nov. 8.
 *      Author: dixi
 */

#ifndef DIAMOND_H_
#define DIAMOND_H_

namespace std {

class Diamond {
public:
  Diamond(int lines);
  void printDiamond();
  virtual ~Diamond();
private:
  int lines;
};

} /* namespace std */

#endif /* DIAMOND_H_ */
