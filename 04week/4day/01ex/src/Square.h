/*
 * Square.h
 *
 *  Created on: 2016. nov. 9.
 *      Author: dixi
 */

#ifndef SQUARE_H_
#define SQUARE_H_

using namespace std;

class Square: public Shape {
  public:
    Square();
    string* getName();
    virtual ~Square();
};



#endif /* SQUARE_H_ */
