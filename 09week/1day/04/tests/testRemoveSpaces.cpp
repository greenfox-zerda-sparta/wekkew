#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../WordToolbox.h"

using namespace std;

TEST_CASE("testing for anagrams") {
  WordToolbox writer("alma");
  REQUIRE(writer.removeSpaces("a l m  a") == "alma");
}

#endif
