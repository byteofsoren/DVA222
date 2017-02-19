#ifndef RENDRER_H
#define RENDRER_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Rendrer
{
private:
    sf::RenderWindow window;
    sf::Event event;
    int width, height;
    std::vector<sf::Shape*> shapes;

public:
    Rendrer(int width, int height);
    virtual ~Rendrer();
    void update();
    void clear();
    int isOpen();
    void draw(sf::Shape *shape);
    void addSapes(sf::Shape *shape);
};

#endif /* RENDRER_H */
