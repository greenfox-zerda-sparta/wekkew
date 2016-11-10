#ifndef SHAPE_H_
#define SHAPE_H_

using namespace std;

class Shape {
  public:
    Shape();
    virtual string* getName();
    virtual void calculateArea();
    virtual ~Shape(){}
  protected:
    double mArea;
};


#endif /* SHAPE_H_ */
