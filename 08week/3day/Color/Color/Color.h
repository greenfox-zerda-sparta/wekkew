#pragma once
#include <string>

using namespace std;

class Color {
public:
  Color();
  Color(unsigned char, unsigned char, unsigned char);
  Color(string);
  Color(Color& other);
  ~Color();
private:
  unsigned char red_;
  unsigned char green_;
  unsigned char blue_;

};

