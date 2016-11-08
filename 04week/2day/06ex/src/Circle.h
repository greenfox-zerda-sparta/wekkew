#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
  private:
    double radius;
    const double pi = 3.1415926535897;
  public:
    Circle(double radius);
    double getCircumference();
    double getArea();
};



#endif /* CIRCLE_H_ */
