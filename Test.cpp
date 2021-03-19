/**
 * Author: Orya Spiegel
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;


//post tests
TEST_CASE("one word posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "")); //empty string
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "abcdefghi"));
    CHECK_NOTHROW(board.post(50, 50, Direction::Vertical, "a")); //one letter string
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "hello"));
    CHECK_NOTHROW(board.post(101, 200, Direction::Horizontal, "world"));
}

TEST_CASE("sentence posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "this is a message board"));
    CHECK_NOTHROW(board.post(50, 50, Direction::Vertical, "this sentence contains five words"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "adding a few numbers 12345"));
    CHECK_NOTHROW(board.post(300, 300, Direction::Vertical, "adding   a   lot   of   spaces"));
}

TEST_CASE("overlapping posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "this is a message board"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "this is a message board"));
    CHECK_NOTHROW(board.post(40, 40, Direction::Horizontal, "hello"));
    CHECK_NOTHROW(board.post(39, 44, Direction::Vertical, "world"));
    CHECK_NOTHROW(board.post(150, 300, Direction::Horizontal, "this is a long message"));
    CHECK_NOTHROW(board.post(150, 310, Direction::Vertical, "shorter"));
}

TEST_CASE("out of border posts")
{
    Board board;
    CHECK_THROWS(board.post(0, -30, Direction::Vertical, "shorter"));
    CHECK_THROWS(board.post(0, -30, Direction::Horizontal, "shorter"));
    CHECK_THROWS(board.post(-20, 30, Direction::Vertical, "abc"));
    CHECK_THROWS(board.post(-20, 30, Direction::Horizontal, "abc"));
    CHECK_THROWS(board.post(-110, -50, Direction::Vertical, "passing a sentence"));
    CHECK_THROWS(board.post(-110, -50, Direction::Horizontal, "passing a sentence"));
    CHECK_THROWS(board.post(-1, -2, Direction::Vertical, "hello"));   //half on the board
    CHECK_THROWS(board.post(-1, -2, Direction::Horizontal, "hello")); //half on the board
    CHECK_THROWS(board.post(5, -2, Direction::Vertical, "hello"));    //half on the board
    CHECK_THROWS(board.post(-2, 5, Direction::Horizontal, "hello"));  //half on the board
}


//read tests
TEST_CASE("read tests")
{
    Board board;
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    CHECK(board.read(50, 50, Direction::Vertical, 5) == "_____");
    CHECK(board.read(100, 200, Direction::Horizontal, 0) == "");
    CHECK(board.read(400, 200, Direction::Horizontal, 1) == "_");
}

TEST_CASE("read out of border tests")
{
    Board board;
    CHECK_THROWS(board.read(-5, 0, Direction::Vertical, 0));
    CHECK_THROWS(board.read(0, -5, Direction::Horizontal, 0));
    CHECK_THROWS(board.read(-100, 200, Direction::Vertical, 10));
    CHECK_THROWS(board.read(100, -200, Direction::Horizontal, 10));
    CHECK_THROWS(board.read(-50, 50, Direction::Vertical, 50));
    CHECK_THROWS(board.read(50, -50, Direction::Horizontal, 50));
    CHECK_THROWS(board.read(-400, -400, Direction::Vertical, 1));
    CHECK_THROWS(board.read(-400, -400, Direction::Horizontal, 1));
}


//post and read tests
TEST_CASE("post & read tests")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "this is a message board"));
    CHECK_NOTHROW(board.post(50, 50, Direction::Vertical, "this sentence contains five words"));
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "adding a few numbers 12345"));
    CHECK_NOTHROW(board.post(400, 200, Direction::Horizontal, "adding   a   lot   of   spaces"));

    CHECK(board.read(0, 0, Direction::Vertical, 23) == "this is a message board");
    CHECK(board.read(0, 0, Direction::Vertical, 5) == "this ");
    CHECK(board.read(50, 50, Direction::Vertical, 33) == "this sentence contains five words");
    CHECK(board.read(55, 50, Direction::Vertical, 28) == "sentence contains five words");
    CHECK(board.read(100, 200, Direction::Horizontal, 26) == "adding a few numbers 12345");
    CHECK(board.read(100, 220, Direction::Horizontal, 26) == " 12345");
    CHECK(board.read(400, 200, Direction::Horizontal, 1) == "adding   a   lot   of   spaces");
}