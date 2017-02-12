#include "game.h"
#include "input.h"
#include <iostream>

using namespace std;


board::board(int rows, int cols){
    // init the board.
    board::rows = rows;
    board::cols = cols;
    // construct the array.
    board::game_board = new int(rows*cols + 1);
    // fill the array with numb^2
    for (int i = 0; i < rows*cols ; ++i) {
        game_board[i] = i;
    }
    game_board[rows*cols + 1] = -1;
}

void board::show(){
    for (int i = 0; i < board::rows; ++i) {
        for (int j = 0; j < board::cols ; ++j){ 
         cout << "---\n" << "|" << board::game_board[i*j] << "|" << "\n" << "---"<<EOF;
        }
    }
}
