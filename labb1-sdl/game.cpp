#include "game.h"
#include <SDL/SDL.h>
#include <SDL2/SDL_render.h>


window::window(int width, int height){
    using namespace std;
    window::width = width;
    window::height = height;
    cout << "Create window" << endl;
    sdlWin = SDL_CreateWindow(
            "N-tiles game",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_OPENGL);
    // Test if it inited else exit with failure
    if (sdlWin == NULL) {
        _Exit(EXIT_FAILURE);
    }
    cout << "init std window" << endl;
    SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &sdlWin, &sdlRend);
    // Test if it inited
    if (sdlRend == NULL) {
        _Exit(EXIT_FAILURE);
    }

    // Start font
    cout << "init fonts" << endl;
    TTF_Init();
    //char font_path[200] = "/usr/share/fonts/TTF/DejaVuSansCondensed.ttf";
    //window::font = TTF_OpenFont(font_path,24);
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/TTF/DejaVuSansCondensed.ttf", 24);
    if (font == NULL) {
        std::cout << "no font found" << std::endl;
        exit(EXIT_FAILURE);
    }
    cout << "Savig fonts in main class" << endl;
    window::font = font;
    if (window::font == NULL){
        std::cout << "No font in main class" << std::endl;
    }

    // Test dwar a rect to se if it worked.
    cout << "Drawing rect" <<endl;
    SDL_Rect rect;
    rect.w = 90;
    rect.h = 60;
    rect.x = window::width/2 - rect.w/2;
    rect.y = window::height/2 - rect.h/2;
    SDL_Rect wellcome;
    SDL_Texture *tture;
   // get_text_and_rect(width/2, height/2,"N-game", &tture, &wellcome);
    SDL_RenderDrawRect(window::sdlRend,&rect);
    SDL_RenderPresent(sdlRend);
    SDL_Delay(100000);
}
window::~window(){
    SDL_DestroyWindow(window::sdlWin);
}
void window::update(){
    while (!rects.empty()) {
       SDL_RenderDrawRect(sdlRend, &rects.back());
       rects.pop_back();
    }
    SDL_RenderPresent(sdlRend);
}

void window::clear()
{
    SDL_RenderClear(sdlRend); 
}

void window::addBox(SDL_Rect rect)
{
    rects.push_back(rect);
    //std::cout << "Added: x=" << rect.x << " y=" << rect.y << " w=" << rect.w << " h=" << rect.h << std::endl;
}

void window::get_text_and_rect(int x, int y, const char *text,  SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(sdlRend, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}


// Tile methods;
tile::tile(int value)
{
    tile::value = value; 
}

int tile::getValue()
{
    return tile::value;
}
void tile::printTile()
{
    std::cout << "Tile value: " << value << std::endl;
}

// Board metthods.
board::board(int rows, int cols, int tileSize)
{
    board::rows = rows;
    board::cols = cols;
    board::tileSize = tileSize;
    board::padding = 4; //px
    board::boardW = (tileSize + padding) * cols;
    board::boardH = (tileSize + padding) * rows;
    // Create tiles
   int errCreate = board::createTiles();
   if (errCreate) {
       std::cout << "No tiles created" << std::endl;
       _exit(EXIT_FAILURE);
   }
}

int board::createTiles()
{
    int totalTileCounter = 0;
    int counter = 3;
    int dontTile = rows * cols;
    for (int row  = 0; row  < rows ; ++row ) {
    //for (int col  = 0; col  < cols ; ++col ) {
        std::vector<tile> temp;
        for (int col  = 0; col  < cols ; ++col ) {
        //for (int row  = 0; row  < rows ; ++row ) {
                std::cout << "row: " << row << "\tcol: " << col << std::endl;
            if (totalTileCounter < dontTile - 1) {
                tile t(counter * counter);
                temp.push_back(t);
                counter++;
                totalTileCounter++;
            }else{
                tile t(-1);
                temp.push_back(t);
                counter++;
                totalTileCounter++;
            }
        }
        board::tiles.push_back(temp);
    }
    //std::cout<<"totalTileCounter="<<totalTileCounter<< std::endl;
    //std::vector<tile> eampty;
    //tile t(-1);
    //eampty.push_back(t);

    //board::tiles.push_back(eampty);
    return 0;
}

int board::boardWidth()
{
    return boardW;
}

int board::boardHeight(){
    return boardH;
}

int  board::getRows()
{
    return rows;
}

int  board::getCols()
{
    return cols;
}

SDL_Rect board::getTile(int row, int col)
{
    SDL_Rect tileRect;
    std::cout << "tile value= " << tiles[row][col].getValue() << std::endl;
    if ((row<=rows)&&(col<=cols)) {
        int value = tiles[row][col].getValue();
        if (value != -1) {
            std::cout << "create tile" << std::endl;
            tileRect.x = (padding + tileSize) * col;
            tileRect.y = (padding + tileSize) * row;
            tileRect.w = tileSize;
            tileRect.h = tileSize;
        }
    }else{
        std::cout << "This got runned " << std::endl;
        tileRect.x = -1;
        tileRect.y = -1;
        tileRect.w = 0;
        tileRect.h = 0;
    }
    return tileRect;
}

int  board::getTileValue(int row, int col)
{
    int value = -1;

    if ((row<=rows)&&(col<=cols)) {
        value = tiles[row][col].getValue();
    }
    return value;

}

int board::moveTile(Move mv)
{
   // Need to fin a wary to only alowe correct movment.
    std::cout << mv << std::endl;
   return 0;
}
