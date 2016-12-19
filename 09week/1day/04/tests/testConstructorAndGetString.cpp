#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../WordToolbox.h"

using namespace std;

TEST_CASE( "constructor and getter" ) {
  WordToolbox noseLess("VOLDEMORT");
  REQUIRE(noseLess.getString() == "VOLDEMORT");
}

#endif
