#include "cliprint.h"
#include <cstdio>
#include <iostream>


Cliprint::Cliprint(Board *board){
    Cliprint::board = board;
}

void Cliprint::createTopFrame(){
    for (int i = 0; i < board->getCols() * 8; ++i) {
        std::cout << "-";
    }
    std::cout << " " << std::endl;
}

void Cliprint::print ()
{
    createTopFrame();
    int rows = board->getRows();
    int cols = board->getCols();
    for (int row  = 0; row  < rows ; ++row ) {
        for (int col  = 0; col  < cols ; ++col ) {
            Brick *brick = board->getBrick(row, col);
            int value = brick->getValue();
            std::cout << "|" ;
            if(value != -1 )std::printf(" %3d |", value);
            else std::cout << "     " << "|" ;
        }
        std::cout << "|" << std::endl;
    }
    createTopFrame();
}
