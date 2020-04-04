/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libsfml
*/

#include "libsfml.hpp"

libSFML::libSFML()
{
    this->_libName.assign("SFML");
    this->window.create(sf::VideoMode(1600, 800), "Arcade - 2019");
    return;
}
 
libSFML::~libSFML()
{
    this->window.close();
    return;
}
 
void libSFML::display(std::vector<std::vector<square_status>> toDisplay)
{
    sf::Texture texture;
    sf::Sprite sprite;
    unsigned int a = 0;
    unsigned int b = 0;
 
    window.clear();
    for (long unsigned int i = 0; i < toDisplay.size(); i++) {
        a = 0;
        for (unsigned int j = 0; j < toDisplay[i].size(); j++) {
            if (toDisplay[i][j] == EMPTY) {
                texture.loadFromFile("assets/sprites/background.png");
                sprite.setTexture(texture);
                sprite.setPosition(sf::Vector2f(a, b));
                window.draw(sprite);
            }
            else if (toDisplay[i][j] == SNAKE_BODY){
                texture.loadFromFile("assets/sprites/s_body.png");
                sprite.setTexture(texture);
                sprite.setPosition(sf::Vector2f(a, b));
                window.draw(sprite);
            }
            else if (toDisplay[i][j] == SNAKE_HEAD){
                texture.loadFromFile("assets/sprites/s_head.png");
                sprite.setTexture(texture);
                sprite.setPosition(sf::Vector2f(a, b));
                window.draw(sprite);
            }
            else {
                texture.loadFromFile("assets/sprites/apple.png");
                sprite.setTexture(texture);
                sprite.setPosition(sf::Vector2f(a, b));
                window.draw(sprite);
            }
            a += 32;
        }
        b += 32;
    }
    this->window.display();
}
 
extern "C"
{
    IGraphical *create_lib()
    {
        return new libSFML();
    }
}