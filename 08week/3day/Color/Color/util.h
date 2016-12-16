#pragma once
#include <iostream>
#include <string>

using namespace std;

bool checkValidHexCode(string hexCode) {
  if (hexCode[0] != '#' && hexCode.length() != 7) {
    throw ("not valid hex code,\ntry #000000 or #ffffff or #FFFFFF format");
  }
  string hexCanContain = "abcdefABCDEF1234567890";
  for (int i = 1; i < 7; i++) {
    if (hexCanContain.find(hexCode[i]) == -1) {
      return false;
    }
  }
  return true;
}