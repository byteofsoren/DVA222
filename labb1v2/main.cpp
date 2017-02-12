#include "board.h"
#include "cliprint.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Start" << std::endl;
    Board b1(4,4);
    std::cout << "Print printBrics." << std::endl;
    //  b1.printBrics();
    std::cout << "Init Cliprint" << std::endl;
    Cliprint printer(&b1);
    std::cout << "Cliprint" << std::endl;
    printer.print();
    b1.moveEmpty(b1.UP);
    printer.print();
    b1.moveEmpty(b1.RIGHT);
    printer.print();
    b1.moveEmpty(b1.LEFT);
    printer.print();
    b1.shuffle(150);
    int running = 1;
    while (running) {
        printer.print();
        std::cout << "-Move-" << std::endl;
        std::cout << " 1 - RIGHT" << std::endl;
        std::cout << " 2 - UP" << std::endl;
        std::cout << " 3 - LEFT" << std::endl;
        std::cout << " 4 - DOWN" << std::endl;
        std::cout << " 0 - EXIT" << std::endl;
        std::cin >> running;
        switch (running) {
            case 0:
                running = 0;
                break;
            case 1:
                b1.moveEmpty(b1.RIGHT);
                break;
            case 2:
                b1.moveEmpty(b1.UP);
                break;
            case 3:
                b1.moveEmpty(b1.LEFT);
                break;
            case 4:
                b1.moveEmpty(b1.DOWN);
                break;
        }
    }
    return 0;
}
