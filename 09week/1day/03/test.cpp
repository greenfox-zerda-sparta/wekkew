#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Fibonacci.h"

TEST_CASE( "Fibonacci happy cases" ) {
  Fibonacci calc;
  REQUIRE(calc.FibonacciNumber(0) == 0);
  REQUIRE(calc.FibonacciNumber(5) == 5);
  REQUIRE(calc.FibonacciNumber(10) == 55);
  REQUIRE(calc.FibonacciNumber(-1) == -1);
}
