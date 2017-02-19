#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include "g_object.hpp"

class Ball: public GObject
{
private:
    sf::Vector2<float> speed;

public:
    Ball(float posx, float posy, float radius);
    virtual ~Ball();
    void setSpeed(float x, float y);
    void setSpeed(sf::Vector2<float> speed);
    void updatePos();
    sf::Vector2<float> *getSpeed();
    float getSpeed(char dir);                   // give X or Y to dir to get speed in that direction
    using GObject::setPos;
    using GObject::getPos;
    using GObject::getShape;
    using GObject::isColidingWith;
};

#endif /* BALL_H */
