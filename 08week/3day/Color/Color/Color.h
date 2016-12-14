#pragma once
class Color {
public:
  Color();
  Color(unsigned char, unsigned char, unsigned char);
  ~Color();
private:
  unsigned char _red_;
  unsigned char _green_;
  unsigned char _blue_;

};

