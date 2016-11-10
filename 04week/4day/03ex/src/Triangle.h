#ifndef TRIANGLE_H_
#define TRIANGLE_H_

using namespace std;

class Triangle: public Shape {
  public:
    Triangle(double height, double width);
    string* getName();
    void calculateArea();
    double getArea();
    virtual ~Triangle(){}
  private:
    double heigth;
    double width;
};


#endif /* TRIANGLE_H_ */
