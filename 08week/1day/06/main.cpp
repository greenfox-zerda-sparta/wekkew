#include <iostream>

// In Your main function create an array of integers. 5 long.
// Fill it up with random numbers.
// For each number treat it as the radius of a circle.
// Calculate the circumference and the area of the circle with such a radius.
// Use preprocessor to define the MY_PI constant. Use this in the calculations.

#include <stdlib.h>
#include <ctime>
#define MyPi 3.1415
#define circumference(r) std::cout << 2 * r * MyPi << endl
#define area(r) std::cout << r * r * MyPi << endl
using namespace std;

int main() {
  srand(time(NULL));
  int array[5];
  for (int i = 0; i < 5; i++) {
    array[i] = rand()%9+1;
  }
  for (int i = 0; i < 5; i++) {
    cout << array[i] << endl;
    circumference(array[i]);
    area(array[i]);
    cout << "-------------" << endl;
  }
  return 0;
}
