#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{
    board my_game = new board(3, 3);
    my_game::show();
    return 0;
}
