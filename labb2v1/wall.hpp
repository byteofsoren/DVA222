#ifndef WALL_H
#define WALL_H
#include "g_object.hpp"
#include "ball.hpp"

class Wall: public GObject
{
private:
    int efect; // Detrmins the action of a wall -1 for bounse 1 for slowdown.

public:
    Wall(float posx, float posy, float width, float height, int efect);
    void action(Ball *ball);
    using GObject::setPos;
    using GObject::setShape;
    using GObject::getPos;
    using GObject::getShape;


};

#endif /* WALL_H */
