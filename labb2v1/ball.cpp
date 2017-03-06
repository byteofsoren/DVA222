#include "ball.hpp"

Ball::Ball() {
    this->setParam(0,0,0);
}

Ball::Ball(float posx, float posy, float radius)
{
    this->setParam(posx,posy,radius);
}

void Ball::setParam(float posx, float posy, float radius)
{
    sf::CircleShape *spere = new sf::CircleShape;
    spere->setRadius(radius);
    spere->setPosition(posx,posy);
    this->setShape(spere);
    this->velocity = 1;
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
void Ball::setVelosity(float ve) {
    this->velocity = ve;
}
void Ball::updatePos() {
    sf::Shape *sf = this->getShape();
    sf::Vector2<float> pos = sf->getPosition();
    pos.x += this->speed.x * this->velocity;
    pos.y += this->speed.y * this->velocity;
    sf->setPosition(pos);
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
