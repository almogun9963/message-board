//
// Created by Almog on 17/03/2021.
//

#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;


// testing positive cases
TEST_CASE("Test positive") {
    Board board;

    CHECK_NOTHROW(board.post(10,10,Direction::Horizontal,"message"));
    CHECK_NOTHROW(board.read(10,10,Direction::Horizontal,7));
    CHECK_NOTHROW(board.read(10,10,Direction::Horizontal,0));
}

// testing negative row and column
TEST_CASE("Test negative") {
    Board board;

//    CHECK_THROWS(board.post(-10,10,Direction::Horizontal,"message"));
//    CHECK_THROWS(board.post(10,-10,Direction::Horizontal,"message"));
//    CHECK_THROWS(board.post(-10,-10,Direction::Horizontal,"message"));
//    CHECK_THROWS(board.read(10,10,Direction::Horizontal,-1));
//    CHECK_THROWS(board.read(-10,-10,Direction::Vertical,-1));
}


// testing general interaction
TEST_CASE("Test general") {
    Board board;

    CHECK(board.read(10,10,Direction::Horizontal,1).compare("_"));//checking the initialization
    CHECK_NOTHROW(board.post(10,10,Direction::Horizontal,"message1"));
    CHECK_NOTHROW(board.read(10,10,Direction::Horizontal, 8));//len("message") = 8
    CHECK(board.read(20,20,Direction::Horizontal,1).compare("_"));//checking that we didn't changed diffrent location
    CHECK(board.read(10,10,Direction::Horizontal,8).compare("message1"));//checking that we didn't changed diffrent location
    CHECK(board.read(10,10,Direction::Horizontal,9).compare("message1_"));
    CHECK(board.read(19,20,Direction::Horizontal,10).compare("_message1_"));

    //same thing, but for vertical
    CHECK(board.read(20,20,Direction::Vertical,1).compare("_"));
    CHECK_NOTHROW(board.post(20,20,Direction::Vertical,"message2"));
    CHECK_NOTHROW(board.read(20,20,Direction::Vertical,8));
    CHECK(board.read(25,25,Direction::Vertical,1).compare("_"));
    CHECK(board.read(20,20,Direction::Vertical,8).compare("message2"));
    CHECK(board.read(20,20,Direction::Vertical,9).compare("message2_"));
    CHECK(board.read(20,19,Direction::Vertical,10).compare("_message2_"));

    CHECK(board.read(10,10,Direction::Horizontal,1).compare(board.read(10,10,Direction::Vertical,1)));//=='m'

    CHECK_NOTHROW(board.post(50,50,Direction::Vertical,"message3"));
    CHECK(board.read(50,50,Direction::Horizontal,2).compare("m_"));
}
