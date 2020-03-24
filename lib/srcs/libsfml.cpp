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
    return;
}

libSFML::~libSFML()
{
    return;
}

void display()
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