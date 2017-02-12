#include <vector>
#include <iostream>

#ifndef BOARD_H
#define BOARD_H

class Board;
class Brick;

class Board
{
private:
    int rows;
    int cols;
    std::vector<Brick> bricks;
    std::vector<Brick>::iterator it;

public:
    enum ValidMove {RIGHT,UP,LEFT,DOWN};
    Board(int rows, int cols);
    int ValidMove(Brick *br, enum ValidMove move);
    virtual ~Board();
    int getRows();
    int getCols();
    Brick *getBrick(int row, int col);
    int moveEmpty(enum ValidMove move);
    void printBrics();
    void shuffle(int nTimes);
};

class Brick
{
private:
    int row;
    int col;
    int value;
public:
    Brick(int row, int col, int value);
    int getValue();
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
    void setValue(int value);
};


#endif /* BOARD_H */
