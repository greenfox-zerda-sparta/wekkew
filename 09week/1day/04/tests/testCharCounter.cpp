#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../WordToolbox.h"

using namespace std;

TEST_CASE("testing for char counter", "countHowMany(char)") {
  WordToolbox strawberry("EPER");
  REQUIRE(strawberry.countHowMany('e') == 0);
  REQUIRE(strawberry.countHowMany('E') == 2);  
}

#endif
