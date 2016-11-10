/*
 * Shape.h
 *
 *  Created on: 2016. nov. 9.
 *      Author: dixi
 */

#ifndef SHAPE_H_
#define SHAPE_H_

using namespace std;

class Shape {

  public:
    Shape();
    virtual string* getName();
    virtual ~Shape();
};


#endif /* SHAPE_H_ */
