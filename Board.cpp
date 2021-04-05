//
// Created by Almog on 17/03/2021.
//

#include <iostream>
#include "Board.hpp"
using namespace std;
namespace ariel {
    void adjust(unsigned int &r, unsigned int &c, Direction &d){
        if(d == Direction::Vertical)
        {
            r=r+1;
        }else
        {
            c=c+1;
        }
    }

    void Board::post(unsigned int r, unsigned int c, Direction d, string m)
    {
        if(highC<c)
        {
            highC=c;
        }
        if(lowC<c)
        {
            lowC=c;
        }
        if(highR<r)
        {
            highR=r;
        }
        if(highC<r)
        {
            lowR=r;
        }
        for(char c1: m)
        {
            board[r][c].val=c1;
            adjust(r,c,d);
        }
    }

    string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int numToRead)
    {
        string s;
        for(unsigned int i=0; i<numToRead; i++)
        {
            s=s+board[r][c].val;
            adjust(r,c,d);
        }
        return s;
    }

    void Board::show()
    {
        for (unsigned int i=lowR; i<=highR; i++)
        {
            for (unsigned int j=lowC; j<=highC; j++)
            {
                cout <<board[i][j].val<< "-";
            }
            cout << "\n";
        }
    }
}
