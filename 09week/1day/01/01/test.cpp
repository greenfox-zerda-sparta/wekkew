#define CATCH_CONFIG_MAIN

#include <stdio.h>
#include "catch.h"
#include "apple.h"
#include <cstdlib>

TEST_CASE("can i have an apple") {
  apple idared;
  REQUIRE(idared.getApple() == "apple");
  system("pause");
}

