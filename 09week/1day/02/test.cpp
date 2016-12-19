#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "numberVector.h"

TEST_CASE("lets start with empty vector") {
  numberVector actualOne;
  REQUIRE(actualOne.getSum() == 0);
}

TEST_CASE("one elemented vector"){
  numberVector actualOne;
  actualOne.addToVector(5);
  REQUIRE(actualOne.getSum() == 5);
}

TEST_CASE("with multiple elemented vector") {
  numberVector actualOne;
  actualOne.addToVector(1);
  actualOne.addToVector(2);
  actualOne.addToVector(3);
  actualOne.addToVector(4);
  REQUIRE(actualOne.getSum() == 10);
}
