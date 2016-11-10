/*
 * Triangle.h
 *
 *  Created on: 2016. nov. 9.
 *      Author: dixi
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;

class Triangle: public Shape {
public:
	Triangle();
	string* getName();
	virtual ~Triangle();
};


#endif /* TRIANGLE_H_ */
