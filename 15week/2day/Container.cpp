#include "Container.hpp"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

Container::Container() {
}

void Container::fill_holding() {
  for (int i = 0; i < 10; i++) {
    holding.push_back(i); 
  }
  for (int i = 20; i < 30; i++) {
    holding.push_back(i);
  }
  copy_holding_to_manip();
}

void Container::copy_holding_to_manip() {
  manip_vector = holding;
  cout << "copied to manip_vector" << endl;
}

void Container::less_then_half(int half) {
  for (int i = 0; i < half; i++) {
    manip_vector.pop_back();
  }
  cout << "deleted back half" << endl;
}

void Container::more_then_half(int half) {
  std::reverse(manip_vector.begin(), manip_vector.end());
  less_then_half(half);
  std::reverse(manip_vector.begin(), manip_vector.end());
  cout << "deleted front half" << endl;
}

bool Container::search(int number) {
  copy_holding_to_manip();
  int half = manip_vector.size() / 2;
  if (number >= manip_vector.front() && number <= manip_vector.back()) {
    while (number != manip_vector[half]) {
      if (manip_vector.empty()) {
        cout << "empty" << endl;
        return false;
      }
      half = half / 2;
      cout << "half is now /2: " << half << "| manip_vector size:" << manip_vector.size() <<endl;
      if (number < manip_vector[half]) {
        less_then_half(half);
      } else {
        more_then_half(half);
      }
      /*if (manip_vector.empty()) {
        return false;
      }*/
    }
    return true;
  }
  else {
    return false;
  }
}


Container::~Container() {}
