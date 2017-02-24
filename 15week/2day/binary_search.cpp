#ifndef TEST
#include <iostream>
#include "Container.hpp"
#include <ios>
using std::cout;
using std::endl;

int main (int argc, char* argv[]) {
  Container cont;
  cont.fill_holding();
  /*if (cont.search(1)) {
    cout << "found" << endl;
  } else {
    cout << "not found" << endl;
  }*/  

  cout << std::boolalpha << cont.search(1) << endl;


  return 0;
}

#endif
