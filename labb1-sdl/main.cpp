#include "game.h"
#include <unistd.h>
#define SEC 100000

int  main(void)
{
    // Init game
    // init gameboard
    // init window
    // init rendrer
    // assign tiles to gameboard
    // do{
    //   draw board
    //   draw tiles
    //   findout posible moves
    //   leisten to keays
    //   Set movment target row coll.
    //   do{
    //      draw board
    //      draw tiles
    //   }while()
    //   is the board sorted? yes=break;
    //  }while()
    board board1(3,6,100);
    window win1(board1.boardWidth(), board1.boardHeight());
   // win1.addBox(board1.getTile(0,0));
    for (int row  = 0; row  < board1.getRows(); ++row ) {
        for (int col = 0; col < board1.getCols() ; ++col ) {
            win1.addBox(board1.getTile(row,col));
        }
    }
    win1.update();
    SDL_Delay(10000);
   
//    usleep(10*SEC);
    return 0;
}
