#pragma once

#include <string>
#include "Direction.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        unsigned int rows;
        unsigned int cols;
    public:
        static void post( unsigned int row,  unsigned int column, Direction direction, string message);
        static string read( unsigned int row,  unsigned int column, Direction direction,  unsigned int numToRead);
        void show();
    };
}