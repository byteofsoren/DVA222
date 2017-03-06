#ifndef WALL_H
#define WALL_H
#include "g_object.hpp"
#include "ball.hpp"

class Wall: public GObject
{
private:
    int efect; // Detrmins the action of a wall -1 for bounse 1 for slowdown.
    std::vector<Ball> *balls;

public:
    Wall(); //No param
    Wall(float posx, float posy, float width, float height, int efect);
    void setParam(float posx, float posy, float width, float height, int efect);
    void action(Ball *ball);
    void addBalls(std::vector<Ball> *p_ball);
    void actOnBalls();
    using GObject::setPos;
    using GObject::setShape;
    using GObject::getPos;
    using GObject::getShape;


};

#endif /* WALL_H */
