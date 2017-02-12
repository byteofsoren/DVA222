#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <strings.h>
#include <string.h>
#include <cstring>
#include <vector>
#ifndef GAME_H
#define GAME_H

enum Move {RIGHT, UP, LEFT, DOWN};
// Class declarations.
class window;
class board;
class tile;
// End class declarations.

class window
{
private:
    SDL_Window *sdlWin;
    SDL_Renderer *sdlRend;
    SDL_Event *sdlEvent;
    //char *font_path;
    std::vector<SDL_Rect> rects;
    std::vector<std::string> text;
    TTF_Font *font;
    void get_text_and_rect(int x, int y, const char *text , SDL_Texture **texture, SDL_Rect *rect);
    int width; int height;  // This is in px

public:
    window(int width, int height);
    virtual ~window();
    void update();
    void clear();
    void addBox(SDL_Rect rect);
    void addText();
};

class tile
{
public:
    tile ( int value);
    int getValue();
    void printTile();
    //virtual ~tile ();

private:
    int value;
};

class board
{
public:
    board (int rows, int cols, int tileSize);
    //virtual ~board ();
    int boardWidth();
    int boardHeight();
    int getRows();
    int getCols();
    int moveTile(Move mv);
    void printBoard();
    SDL_Rect getTile(int row, int col);
    int getTileValue(int row, int col);


private:
    int rows;
    int cols;
    int tileSize;
    int boardW;
    int boardH;
    int padding;
    int createTiles();
    std::vector<std::vector<tile> > tiles;
};

#endif /* GAME_H */
