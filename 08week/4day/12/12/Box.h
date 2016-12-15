#pragma once

using namespace std;

enum elemType { VECTOR, INTEGER };

class Box {
public:
  elemType type;
  vector<Box> doboz;
  int integer;
};
