#ifndef G_OBJECT_H
#define G_OBJECT_H
#include <SFML/Graphics.hpp>
#include <vector>

class GObject
{
private:
    //sf::Rect<float> bondary;
    sf::Shape *shape;


public:
    GObject();
    GObject(sf::Shape *sh);
    virtual ~GObject();
    void setShape(sf::Shape * sh);
    sf::Shape *getShape();
    int isColidingWith(GObject *object);
    void setPos(float x, float y);;
    sf::Vector2<float> getPos();

};

#endif /* G_OBJECT_H */
