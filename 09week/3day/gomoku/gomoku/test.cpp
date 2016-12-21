#define TEST
#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "../../../2day/bankAccount/test/catch.h"
#include "Gomoku.h"

TEST_CASE("instance has a matrix for the board") {
  Gomoku game;
  REQUIRE(game.board.size() != 0);
}

TEST_CASE("board is filled with \"0\"-s"){
  Gomoku game;
  REQUIRE(game.board[4][7] == 0);
}

TEST_CASE("class has a constant variable for the size with a default 19 value") {
  Gomoku game;
  REQUIRE(game.size == 19);
}

TEST_CASE("create a method which decides based on the stepcounter what to put") {
  Gomoku game;
  game.step(1, 1);
  game.step(2, 2);
  game.step(3, 3);
  REQUIRE(game.board[1][1] == 1);
  REQUIRE(game.board[2][2] == 2);
  REQUIRE(game.board[3][3] == 1);
}

TEST_CASE("after the 9th step -> checking method") {
  Gomoku game;
  game.step(1, 1);
  game.step(2, 2);
  game.step(0, 0);
  game.step(3, 3);
  REQUIRE(game.startCheck == false);
  /*game.step(4, 3);
  game.step(5, 1);
  game.step(6, 2);
  game.step(7, 1);
  game.step(8, 2);
  REQUIRE(game.startCheck == true); */
}

TEST_CASE("check method check 5 in a row backwards") {
  Gomoku game;
  game.step(0, 0);  //1
  game.step(1, 0);  //2
  CHECK(game.board[0][0] == 1);
  CHECK(game.board[1][0] == 2);
  game.step(0, 1);  //3
  game.step(1, 1);  //4
  CHECK(game.board[1][1] == 2);
  game.step(0, 2);  //5
  CHECK(game.board[0][2] == 1);
  game.step(1, 2);  //6
  game.step(0, 3);  //7
  game.step(1, 3);  //8
  game.step(0, 4);  //9
//  game.step(1, 4);  //10
//  game.step(0, 5);  //11
  REQUIRE(game.startCheck == true);
  REQUIRE(game.win == true);
}

#endif
