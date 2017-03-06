#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "rendrer.hpp"
#include "ball.hpp"
#include "wall.hpp"
#define NRWALLS 6
#define NRBALLS 4

void test_render()
{
    Rendrer *ren = new Rendrer(640,480);
    sf::CircleShape  circle(30);
   // ren->draw(&circle);
    circle.setPosition(10,10);
    ren->addSapes(&circle);
    ren->update();
    sleep(4);
    circle.setPosition(30,30);
    ren->update();
    sleep(5);
}


int main(int argc, char *argv[])
{
    //test_render();
    // Start a rendrer object, it wihll take with and hight.
    // Create ball.
    // Create Walls.
    // Add ball and walls to rendrer.
    // update pos for the ball.
    // Wait untill end.
    Rendrer *render = new Rendrer(640,480);
//   boll1->setSpeed(2,3);
//    boll2->setSpeed(1,0);
//    boll3->setSpeed(1,-1);
    std::vector<Ball> *my_balls = new std::vector<Ball>;
    for (int i = 0; i < NRBALLS; ++i) {
        my_balls->push_back(Ball(10*i,30+1,4));
        render->addSapes(my_balls->at(i).getShape());
    }
    std::vector<Wall> *my_walls = new std::vector<Wall>;
    for (int i = 0; i < NRWALLS; ++i) {
        my_walls->push_back(Wall());
        render->addSapes(my_walls->at(i).getShape());
    }
    // Ball configurations
    my_balls->at(0).setSpeed(1, 0.03);
    my_balls->at(1).setSpeed(0.05, -1);
    my_balls->at(2).setSpeed(-0.04, 0.03);
    // Wall configuration
    my_walls->at(0).setParam(0,0,1,600,-1); // Left Screen border
    my_walls->at(1).setParam(0,0,800,1,-1); // Top Screan border
    my_walls->at(2).setParam(600,0,1,600,-1); // Bot Screen boreer
    my_walls->at(3).setParam(0,800,800,1,-1); // right Sreen border

    my_walls->at(4).setParam(200,100,50,20,0); // right Sreen border
    // Main loop to update streen
    render->update();
    while (render->isOpen()) {
        std::cout<<"In render loop" << std::endl;
        for (size_t i = 0; i < my_balls->size(); ++i) {
            my_balls->at(i).updatePos();
        }
        render->update();
        usleep(100);
    }
    my_balls->clear();

    return 0;
}
