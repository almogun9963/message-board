//
// Created by Almog on 17/03/2021.
//

#pragma once

#include <string>
#include "Direction.hpp"
#include "Direction.hpp"
#include <map>
#include <limits>
using namespace std;
struct temp{
    char val = '_';
};

namespace ariel {
    class Board {
        unsigned int highC;
        unsigned int lowC;
        unsigned int highR;
        unsigned int lowR;
        map<unsigned int, map<unsigned int, temp> > board;

    public:
        Board() {
            highC=0;
            lowC=std::numeric_limits<int>::max();
            highR=0;
            lowR=std::numeric_limits<int>::max();
        }
        void post(unsigned int r, unsigned int c, Direction d, string m);
        string read(unsigned int r, unsigned int c, Direction d, unsigned int numToRead);
        void show();
        ~Board() {}
    };
}