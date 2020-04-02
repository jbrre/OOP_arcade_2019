/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libncurses
*/

#include <curses.h>
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

void libNCurses::display(std::vector<std::vector<square_status>> toDisplay) const
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