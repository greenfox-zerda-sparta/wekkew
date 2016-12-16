#include "Color.h"
#include "util.h"

Color::Color() : red_(0), green_(0), blue_(0) {
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue) {
  red_ = red;
  green_ = green;
  blue_ = blue;
}

Color::Color(string hexCode) {
  try {
    if (checkValidHexCode(hexCode)) {
      cout << "valid" << endl;
    }
  }
  catch (const char* errormessage) {
    cout << errormessage << endl;
  }
}

Color::Color(Color& other) {
  other.red_ = red_;
  other.green_ = green_;
  other.blue_ = blue_;
}

Color::~Color() {
}
