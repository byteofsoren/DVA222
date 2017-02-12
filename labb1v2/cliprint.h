#include "board.h"

#ifndef CLIPRINT_H
#define CLIPRINT_H

class Cliprint
{
private:
    Board *board;
public:
    Cliprint(Board *board);
    void createTopFrame();
    void print();
};

#endif /* CLIPRINT_H */ 
