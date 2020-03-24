/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libncurses
*/

#include "libncurses.hpp"

libNCurses::libNCurses()
{
    this->_libName.assign("ncurses");
    return;
}

libNCurses::~libNCurses()
{
    return;
}

void libNCurses::display()
{
    return;
}

extern "C"
{
    IGraphical *create_lib()
    {
        return new libNCurses();
    }
}