#include "board.h"
#include <utility>
#include <random>
#include <iostream>


int _getVectorPos(int row, int col ,int cols){
    return  row*(cols )+col;
}
// #Board class;
Board::Board(int rows, int cols){
    Board::rows = rows;
    Board::cols = cols;
    int counter = 3;
    // Create brics in a 2D array.
    for (int r = 0; r < rows ; ++r) {
        for (int c = 0; c < cols ; ++c) {
            Brick *b = new Brick(r, c, counter*counter);
            Board::bricks.push_back(*b);
            counter++;
        }
    }
    // Change last brick to no brick aka -1.
    Brick *lastBrick = new Brick(rows-1, cols-1, -1);
    Board::bricks.pop_back();
    Board::bricks.push_back(*lastBrick);
    //it +=  counter;
    //it->setValue(-1);
}
int Board::getRows(){
    return rows;

}
int Board::getCols()
{
    return cols;
}

int Board::ValidMove(Brick *br, enum ValidMove move){
    int succesfull= 0;
    int col = br->getCol();
    int row = br->getRow();
    // Is it inside 
    // first set cols
    //std::cout << "ValidMove() col=" << col << "\trow=" << row << std::endl;
    switch (move ) {
        case UP:
            row--;
            break;
        case DOWN:
            row++;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
    }
        // Now do thot fit itside the array?
   // std::cout << "ValidMove() col=" << col << "\trow=" << row << std::endl;
    if ((col<cols)&&(col>=0)&&(row<rows)&&(row>=0)) {
        //std::cout<< "-- Valid --" << std::endl;
        succesfull= 1;
    }
    return succesfull;
}

int  Board::moveEmpty(enum ValidMove move)
{
    // this function moves the tile in a direction.
    // Not implemente
    int i = 0;
    Brick *emptyBr;
    do {
        emptyBr = &Board::bricks[i];
        i++;
    } while (emptyBr->getValue() != -1   );
    i--;
    int succesfull = 0;
    int row = emptyBr->getRow();
    int col = emptyBr->getCol();
    //std::cout << "moveEmpty row=" << row << "\tcol=" << col <<std::endl;
    if (ValidMove(emptyBr,move) == 1) {
        switch (move ) {
            case UP:
                row--;
                break;
            case DOWN:
                row++;
                break;
            case LEFT:
                col--;
                break;
            case RIGHT:
                col++;
            
                 //std::cout << "FAILURE" << std::endl;
        }
        //std::cout << "Swapp row=" << row << "\tcol=" << col << std::endl;
        int swapPos = _getVectorPos(row,col,cols);
        //i = 2;
        //std::cout << "Swappnig  i=" <<i << " With swapPos="<< swapPos<< std::endl;
        //std::cout << bricks[i].getValue() << "\twith " << bricks[swapPos].getValue() << std::endl;
        // Need to swap info in the brics...
        bricks[swapPos].setRow(emptyBr->getRow());
        bricks[swapPos].setCol(emptyBr->getCol());
        bricks[i].setRow(row);
        bricks[i].setCol(col);
        std::swap(bricks[i] , bricks[swapPos]);
        succesfull = 1;
    }
    return succesfull;
}
void Board::printBrics()
{
    for (it = bricks.begin() ; it != bricks.end(); ++it) {
        int val =  it->getValue();
        int r = it->getRow();
        int c = it->getCol();
        std::cout << "Bric: value=" <<  val << "\trow=" << r << "\tcol=" << c << std::endl;
    }
}
Brick* Board::getBrick(int row, int col)
{
    if ((row<=rows)&&(col<=cols)) {
        Brick *b = NULL;
        b = &bricks[_getVectorPos(row,col,cols)];
        return b;
    }
    return NULL;
}

int  _genRandom(int min, int max)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    int random_integer = uni(rng);
    return random_integer;
}

void Board::shuffle(int nTimes)
{
    //std::cout << "Shuffle nTimes=" << nTimes << " _genRandom(0,4)=" << _genRandom(0,4) << std::endl;
    int counter = 0;
    int moves = 0;
    while (counter < nTimes) {
        int ran = _genRandom(1,4);
        int succesfull = 0;
        switch (ran ) {
            case 1:
                succesfull = moveEmpty(RIGHT);
                break;
            case 2:
                succesfull = moveEmpty(UP);
                break;
            case 3:
                succesfull = moveEmpty(LEFT);
                break;
            default:
                succesfull = moveEmpty(DOWN);
        }
        if(succesfull) counter++;
        moves++;
        if (moves == 10000) {
            // Safte first
            break;
        }
    }
    //std::cout << "Counter ouput is " << counter << std::endl;
}

Board::~Board()
{

}

// #Bric class
Brick::Brick(int row, int col, int value){
    Brick::row = row;
    Brick::col = col;
    Brick::value = value;
}

int  Brick::getValue()
{
    return value;
}
int  Brick::getRow()
{
    return row;
}
int  Brick::getCol()
{
    return col;
}

void Brick::setRow(int row)
{
    Brick::row = row;
}

void Brick::setCol(int col)
{
    Brick::col = col;
}

void Brick::setValue(int value)
{
    Brick::value = value;
}
