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
    int y = 10;

    clear();
    for (int i = 0; i < toDisplay.size(); i++, y++) {
        for (int j = 0; j < toDisplay[i].size(); j++) {
	    if (toDisplay[i][j] == EMPTY)
	        mvprintw(y, (COLS/2), ' ');
	    else if (toDisplay[i][j] == APPLE)
	        mvprintw(y, (COLS/2), 'o');
	    else if (toDisplay[i][j] == SNAKE_HEAD)
		mvprintw(y, (COLS/2), 'p');
	    else if (toDisplay[i][j] == SNAKE_BODY)
		mvprintw(y, (COLS/2), 't');
	    else if (toDisplay[i][j] == WALL)
		mvprintw(y, (COLS/2), '|');
	    else if (toDisplay[i][j] == PLAYER)
		mvprintw(y, (COLS/2), 'P');
	    else if (toDisplay[i][j] == GHOST)
		mvprintw(y, (COLS/2), 'A');
	    else if (toDisplay[i][j] == POINT)
		mvprintw(y, (COLS/2), 'o');
	}
    }
    refresh();
    return;
}

extern "C"
{
    IGraphical *create_lib()
    {
        return new libNCurses();
    }
}
