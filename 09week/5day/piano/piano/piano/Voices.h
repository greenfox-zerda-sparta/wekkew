#pragma once
#include <map>
#include <Windows.h>

using namespace std;

class Voices {
private:
  map<int, double> sounds;
  int duration;
public:
  Voices();
  void playSound(int);
  ~Voices();
private:
  void fillSounds();
};

