#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "../account.h"
#include <utility>

TEST_CASE("constructor takes a string for name") {
  Account account("Tojas");
}

TEST_CASE("balance set to 0") {
  Account account("tojas");
  REQUIRE(account.balance == 0);
}

TEST_CASE("getBalance method returns balance value") {
  Account account("Tojas");
  REQUIRE(account.getBalance() == 0);
}

TEST_CASE("topUp method && test getBalance for not 0 balance"){
  Account account("Tojas");
  double amount = 10;
  account.topUp(amount);
  REQUIRE(account.getBalance() == Approx(amount));
}

#endif
