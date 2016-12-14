#include "Color.h"

Color::Color() {
  _red_ = 0;
  _green_ = 0;
  _blue_ = 0;
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
  _red_ = red;
  _green_ = green;
  _blue_ = blue;
}


Color::~Color() {
}
