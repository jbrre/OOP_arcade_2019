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

void display(std::vector<std::vector<square_status>> toDisplay)
{
    return;
}

extern "C"
{
    IGraphical *create_lib()
    {
        return new libSFML();
    }
}