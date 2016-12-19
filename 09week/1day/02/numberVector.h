#ifndef NUMBERVECTOR_H
#define NUMBERVECTOR_H

#include <vector>

using namespace std;

class numberVector {
private:
  vector<int> storage;
public:
  numberVector() {};
  int getSum();
  void addToVector(int);
  ~numberVector() {};
};

#endif
