#include "rendrer.hpp"

Rendrer::Rendrer(int width, int height){
    Rendrer::width = width;
    Rendrer::height = height;
    window.create(sf::VideoMode(width,height),"Game");
    window.clear(sf::Color::Black);
    window.pollEvent(this->event);
}

Rendrer::~Rendrer(){}

void Rendrer::update(){
    window.clear(sf::Color::Black);
    for(std::vector<sf::Shape*>::iterator it = this->shapes.begin(); it != this->shapes.end(); it++){
        this->draw(*it);
        //std::cout << "showinng grapics"<<std::endl;
    }
    window.display();
}
void Rendrer::clear(){
    while (window.pollEvent(Rendrer::event)) {
        if (event.type == sf::Event::Closed) {
          // Rendrer::~Rendrer();
          window.close();
        }
    }
}

void Rendrer::draw(sf::Shape *shape){
    window.draw(*shape);
}

void Rendrer::addSapes(sf::Shape *shape) {
    this->shapes.push_back(shape);
}
int Rendrer::isOpen() {
    while (window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            return 0;
        }else
            return 1;
    }
    return 1;
}
