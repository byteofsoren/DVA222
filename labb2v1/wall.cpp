#include "wall.hpp"

Wall::Wall() {
    this->setParam(0, 0, 0, 0, 0);  // Cale as eperate funcion to set porp
}

Wall::Wall(float posx, float posy, float width, float height, int efect) {
    this->setParam(posx, posy, width, height, efect);  // Cale as eperate funcion to set porp
}

void Wall::setParam(float posx, float posy, float width, float height, int efect) {


    sf::RectangleShape *rect = new sf::RectangleShape;
    rect->setPosition(posx,posy);
    sf::Vector2<float> size;
    size.x = width;
    size.y = height;
    rect->setSize(size);
    if (efect == -1) {
        // Bounce collor this is a wall.
        rect->setFillColor(sf::Color::Yellow);
    } else if (efect == 0){
        // Slow Down
        rect->setFillColor(sf::Color::Blue);
    }else{
        // Speed upp oother wise
        rect->setFillColor(sf::Color::Red);
    }
    GObject::setShape(rect);
    this->efect = efect;
}

void Wall::action(Ball *ball) {
    //This is the monny maker of the program.
    // If a ball hitt a wall and calls this function then this function decides
    // wath to da with the ball.
    // It all depend on what type of wall it is that is specefied in the efect
    // variable.
    sf::Vector2<float> *speed = ball->getSpeed();
    switch (efect) {
        case -1: {
            // This is a wall
            float tempx = speed->x;
            float tempy = speed->y;
            speed->x = tempy;
            speed->y = tempx;
            break;
        }
        case 0: {
            // This is slowing down
            speed->x *= 0.9;
            speed->y *= 0.9;

            break;
        }
        default:
        //Speed up.
            speed->x *= 1.1;
            speed->y *= 1.1;
    }
}
void Wall::addBalls(std::vector<Ball> *p_ball) {
    this->balls = p_ball;
}

void Wall::actOnBalls() {
    std::vector<Ball>::iterator it;
    for(it = this->balls->begin(); it != this->balls->end(); it++){
        this->action(&*it);
    }
    
}
