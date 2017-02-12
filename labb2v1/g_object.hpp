#ifndef G_OBJECT_H
#define G_OBJECT_H
#include <SFML/Graphics.hpp>
#include <vector>

class GObject
{
private:
    sf::Vector2<float> pos;
    

public:
    GObject();
    virtual ~GObject();
    int isColidingWith(sf::Shape *sh);
    void setPos(sf::Vector2<float> pos);
    sf::Vector2<float> getPos();

};

#endif /* G_OBJECT_H */
