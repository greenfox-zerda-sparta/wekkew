#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../WordToolbox.h"

using namespace std;

TEST_CASE("testing for howmany kind of anagrams") {
  WordToolbox apple("alma");
  REQUIRE(apple.checkWithCount("l ama ") == true);
}

#endif
