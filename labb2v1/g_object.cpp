#include "g_object.hpp"

GObject::GObject()
{
    this->shape = NULL;
}
GObject::GObject(sf::Shape *sh){
    GObject::shape =  sh;
    //GObject::bondary = sh->getGlobalBounds();
}
void GObject::setShape(sf::Shape *sh)
{
    this->shape = sh;
}
GObject::~GObject()
{
    free(this->shape);
}
void GObject::setPos(float x,float y){
   // GObject::pos = pos;
    //GObject::bondary.left = x;
    //GObject::bondary.top = y;
    GObject::shape->setPosition(x,y);
}
sf::Shape *GObject::getShape()
{
    return this->shape;
}
sf::Vector2<float> GObject::getPos()
{
    sf::Vector2<float> pos;
    pos = this->shape->getPosition();
    return pos;
}
int GObject::isColidingWith(GObject *object)
{
    sf::Rect<float> myshape = this->shape->getGlobalBounds();
    sf::Rect<float> otshape = object->shape->getGlobalBounds();
    return myshape.intersects(otshape);
}
