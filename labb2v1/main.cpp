#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "rendrer.hpp"
#include "ball.hpp"
#include "wall.hpp"

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
    Ball *boll1 = new Ball(10,10,30);
    Ball *boll2 = new Ball(50,90,40);
    Ball *boll3 = new Ball(100,20,50);
    boll1->setSpeed(2,3);
    boll2->setSpeed(1,0);
    boll3->setSpeed(1,-1);
    Wall *w1 = new Wall(1,10,30,200,0);
    Wall *w2 = new Wall(800,100,30,200,-1);
    render->addSapes(boll1->getShape());
    render->addSapes(boll2->getShape());
    render->addSapes(boll3->getShape());
    render->addSapes(w1->getShape());
    render->addSapes(w2->getShape());
    render->update();
    int running = 1;
    while (running) {
        running = render->isOpen();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            running = 0;
        }
        boll1->updatePos();
        boll2->updatePos();
        boll3->updatePos();
        if (boll1->isColidingWith(w1)) {
            w1->action(boll1);
        }
        if (boll1->isColidingWith(w2)) {
            w2->action(boll1);
        }
        
        if (boll2->isColidingWith(w1)) {
            w1->action(boll2);
        }
        if (boll2->isColidingWith(w2)) {
            w2->action(boll2);
        }
        
        if (boll3->isColidingWith(w1)) {
            w1->action(boll3);
        }
        if (boll3->isColidingWith(w2)) {
            w2->action(boll3);
        }
       render->update();
        usleep(100);
    }

    return 0;
}
