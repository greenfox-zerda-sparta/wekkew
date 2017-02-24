#ifdef TEST 

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include <iostream>
#include "Container.hpp"

using std::cout;
using std::endl;

void print_holding(vector<int> vector) {
  for (int i = 0; i < vector.size(); i++) {
    cout << vector[i] << " | ";
  }
}

TEST_CASE("Container class exists") {
  Container cont;
}

TEST_CASE("Container has and empty vector after construction") {
  Container cont;
  REQUIRE(cont.holding.size() == 0);
}

TEST_CASE("Conainer fill_holding() method fills holding with 100 elements") {
  Container cont;
  cont.fill_holding();
  REQUIRE(cont.holding.size() == 20);
}

TEST_CASE("Container's search(int) method returnes true") {
  Container cont;
  cont.fill_holding();
  REQUIRE(cont.search(5));
}


TEST_CASE("Container's search(int) method returnes true if number is less or equal then holding's max value and false if not") {
  Container cont;
  cont.fill_holding();
  //print_holding(cont.holding);
  REQUIRE(cont.search(2));
  REQUIRE_FALSE(cont.search(-1));
  REQUIRE_FALSE(cont.search(11));
}

TEST_CASE("Container has an extra vector to manupulate by the serach(int) method") {
  Container cont;
  cont.fill_holding();
  REQUIRE(cont.holding.size() == cont.manip_vector.size());
}

TEST_CASE("Container's search(int number) method \"cuts\" the extra half of vector if number is in the range") {
  Container cont;
  cont.fill_holding();
  REQUIRE(cont.manip_vector.size() == 20);
  REQUIRE(cont.search(5));
}

TEST_CASE("holgin conts 0-9, 20-29") {
  Container cont;
  cont.fill_holding();
  REQUIRE(cont.search(5));
  //REQUIRE(cont.search(25));
  //REQUIRE_FALSE(cont.search(15));
}


#endif // end of #ifdef TEST
