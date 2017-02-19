#include "ball.hpp"

Ball::Ball(float posx, float posy, float radius)
{
    sf::CircleShape *spere = new sf::CircleShape;
    spere->setRadius(radius);
    spere->setPosition(posx,posy);
    this->setShape(spere);
}
Ball::~Ball()
{
    
}
void Ball::setSpeed(float x, float y)
{
    this->speed.x = x;
    this->speed.y = y;
}
void Ball::setSpeed(sf::Vector2<float> speed)
{
    this->speed = speed;
}
void Ball::updatePos() {
    sf::Vector2<float> pos = this->getPos();
    pos.x += this->speed.x;
    pos.y += this->speed.y;
    this->setPos(pos.x, pos.y);
}
sf::Vector2<float>* Ball::getSpeed()
{
    return &this->speed;
}
float Ball::getSpeed(char dir)
{
    if ((dir == 'x')||(dir == 'X'))
        return this->speed.x;

    return this->speed.y; // Defoultly asuming return y

}
