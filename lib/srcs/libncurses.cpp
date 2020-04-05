/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libncurses
*/

#include <iostream>
#include <ncurses.h>
#include "libncurses.hpp"

libNCurses::libNCurses()
{
    this->_libName.assign("ncurses");
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    nodelay(stdscr, TRUE);
    return;
}

libNCurses::~libNCurses()
{
    return;
}

void libNCurses::addKeyToEnv(int key)
{
    if (keyboard.count(key)) {
        this->_env->addEvent(keyboard.find(key)->second);
    }
}

void libNCurses::display(std::vector<std::vector<square_status>> toDisplay)
{
    int y = 0;
    int z = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    int key = 0;

    key = getch();
    this->addKeyToEnv(key);
    clear();
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    for (; i < toDisplay.size(); i++, y++) {
        for (; j < toDisplay[i].size(); j++, z++) {
	    if (toDisplay[i][j] == EMPTY) {
    	    	attron(COLOR_PAIR(3));
    	        mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "J");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == APPLE) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "o");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == SNAKE_HEAD) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "p");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == SNAKE_BODY) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8,  "t");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == WALL) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "|");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == PLAYER) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "P");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == GHOST) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "A");
    	    	attroff(COLOR_PAIR(3));
    	    }
    	    if (toDisplay[i][j] == POINT) {
    	    	attron(COLOR_PAIR(3));
    	    	mvprintw((LINES/2) + y - 8, (COLS/2) + z - 8, "o");
    	    	attroff(COLOR_PAIR(3));
    	    }
        }
	j = 0;
	z = 0;
    }
    refresh();
}

void libNCurses::print_menu(std::string ascii[6], std::string pacman[5], int color_s, int color_p) const
{
    char str [100];
    int y = 10;

    for (int i = 0; i < 6; i++, y++) {
        ascii[i].copy(str, ascii[i].size() + 1);
        str[ascii[i].size()] = '\0';
        attron(COLOR_PAIR(color_s));
        mvprintw(y, (COLS/2) - 60, str);
        attroff(COLOR_PAIR(color_s));
    }
    y = 10;
    for (int j = 0; j < 5; j++, y++) {
    attron(COLOR_PAIR(color_p));
    pacman[j].copy(str, pacman[j].size() + 1);
    str[pacman[j].size()] = '\0';
    mvprintw(y, COLS/2 + 10, str);
    attroff(COLOR_PAIR(color_p));
    }
}

const std::string libNCurses::menu(void) const
{
    int key;
    int color_s = 1;
    int color_p = 2;
    std::string snake[6] {"                      __           ",
            "  ______ ____ _____  |  | __ ____  ",
            " /  ___//    \\\\__  \\ |  |/ // __ \\ ",
            " \\___ \\|   |  \\/ __ \\|    <\\  ___/ ",
            "/____  >___|  (____  /__|_ \\\\___  >",
            "     \\/     \\/     \\/     \\/    \\/ "};

    std::string pacman[5] { "___________    ____   _____ _____    ____  ",
            "\\____ \\__  \\ _/ ___\\ /     \\\\__  \\  /    \\ ",
            "|  |_> > __ \\\\  \\___|  Y Y  \\/ __ \\|   |  \\ ",
            "|   __(____  /\\___  >__|_|  (____  /___|  /" ,
            "|__|       \\/     \\/      \\/     \\/     \\/ "
           };
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    
    while (1) {
        this->print_menu( snake, pacman, color_s, color_p);
        key = getch();
        if (key == '\n' && color_p == 2) {
            return ("./games/lib_arcade_nibbler.so");
        } else if (key == '\n' && color_s == 2) {
            return ("./games/lib_arcade_pacman.so");
        } else if (key == KEY_RIGHT) {
            color_s = 2;
            color_p = 1;
        } else if (key == KEY_LEFT) {
            color_s = 1;
            color_p = 2;
        }
        refresh();
        clear();
    }
    return ("");
}

extern "C"
{
    IGraphical *create_lib()
    {
        return new libNCurses();
    }
}
