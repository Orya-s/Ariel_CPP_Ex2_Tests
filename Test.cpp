/**
 * Author: Orya Spiegel
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;
#include <string>
#include <algorithm>
using namespace std;

//read tests
TEST_CASE("read tests")
{
    Board board;
    CHECK(board.read(0,0,Direction::Vertical,0) == "");
    CHECK(board.read(50,50,Direction::Vertical,5) == "_____");
    CHECK(board.read(100,200,Direction::Horizontal,0) == "");
    CHECK(board.read(400,200,Direction::Horizontal,1) == "_");
}


//post tests
TEST_CASE("one word posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"abcdefghi"));
    CHECK_NOTHROW(board.post(50,50,Direction::Vertical,"a"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"hello"));
    CHECK_NOTHROW(board.post(101,200,Direction::Horizontal,"world"));
}

TEST_CASE("sentence posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"this is a message board"));
    CHECK_NOTHROW(board.post(50,50,Direction::Vertical,"this sentence contains five words"));
    CHECK_NOTHROW(board.post(100,200,Direction::Horizontal,"adding a few numbers 12345"));
    CHECK_NOTHROW(board.post(300,300,Direction::Vertical,"adding   a   lot   of   spaces"));
}

TEST_CASE("overlapping posts")
{
    Board board;
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"this is a message board"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"this is a message board"));
    CHECK_NOTHROW(board.post(40,40,Direction::Horizontal,"hello"));
    CHECK_NOTHROW(board.post(39,44,Direction::Vertical,"world"));
    CHECK_NOTHROW(board.post(150,300,Direction::Horizontal,"this is a long message"));
    CHECK_NOTHROW(board.post(150,310,Direction::Vertical,"shorter"));
}



//post and read tests




