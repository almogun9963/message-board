//
// Created by Almog on 17/03/2021.
//

#include <iostream>
#include "Board.hpp"
using namespace std;
namespace ariel {

    void Board::post(unsigned int row, unsigned int column, Direction direction, string message) {
        message = message + ",";
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int numToRead) {
        return " ";
    }

    void Board::show() {
    }
}