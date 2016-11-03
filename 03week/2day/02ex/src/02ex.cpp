#include <string>
#include <iostream>

using namespace std;

struct RectangularCuboid {
  double a;
  double b;
  double c;
};

int getSurface(RectangularCuboid rectangular) {
  return 2*rectangular.a*rectangular.b + 2*rectangular.a*rectangular.c + 2*rectangular.b*rectangular.c;
}
int getVolume(RectangularCuboid rectangular) {
  return rectangular.a*rectangular.b*rectangular.c;
}

// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface

// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int main() {
  RectangularCuboid box;
  box.a = 10;
  box.b = 20;
  box.c = 40;
  cout << "surface: " << getSurface(box) << endl;
  cout << "volume: " << getVolume(box) << endl;

  return 0;
}

