#ifndef SQUARE_H_
#define SQUARE_H_

using namespace std;

class Square: public Shape {
  public:
    Square(double heigth);
    string* getName();
    void calculateArea();
    double getArea();
    virtual ~Square(){}
   private:
    double heigth;
};



#endif /* SQUARE_H_ */
