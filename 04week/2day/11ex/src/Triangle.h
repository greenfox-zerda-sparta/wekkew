#ifndef TRIANGLE_H_
#define TRIANGLE_H_

namespace std {

class Triangle {
public:
  Triangle(int lines);
  void printTriangle();
  virtual ~Triangle();
private:
  int lines;
};

} /* namespace std */

#endif /* TRIANGLE_H_ */
