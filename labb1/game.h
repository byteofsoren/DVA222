
#ifndef GAME_H
#define GAME_H

typedef struct boardpos_st{
    int row;
    int col;
} boardPos;

class board
{
private:
    int *game_board;
    int rows;
    int cols;
public:
    board(int rows, int cols);
    virtual ~board();
    int moveBric(boardPos from, boardPos to);
    void show();
    void scramble();
};
class interface{
public:
   void draw();
   void ask();
};
#endif /* GAME_H */

