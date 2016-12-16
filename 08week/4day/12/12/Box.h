#pragma once

using namespace std;

enum elemType { VECTOR, INTEGER, IFUCKINGDONTCARE };

class Box {
public:
  elemType type;
  vector<Box> doboz;
  int integer;
};
