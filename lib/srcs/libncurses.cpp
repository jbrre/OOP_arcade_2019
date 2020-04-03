/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libncurses
*/

#include <ncurses.h>
#include "libncurses.hpp"

libNCurses::libNCurses()
{
    this->_libName.assign("ncurses");
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    return;
}

libNCurses::~libNCurses()
{
    return;
}

void libNCurses::display(std::vector<std::vector<square_status>> toDisplay) const
{
    // int y = 10;

    // clear();
    // for (int i = 0; i < toDisplay.size(); i++, y++) {
    //     for (int j = 0; j < toDisplay[i].size(); j++) {
    //     if (toDisplay[i][j] == EMPTY)
    //         mvprintw(y, (COLS/2), ' ');
    //     else if (toDisplay[i][j] == APPLE)
    //         mvprintw(y, (COLS/2), 'o');
    //     else if (toDisplay[i][j] == SNAKE_HEAD)
    //     mvprintw(y, (COLS/2), 'p');
    //     else if (toDisplay[i][j] == SNAKE_BODY)
    //     mvprintw(y, (COLS/2), 't');
    //     else if (toDisplay[i][j] == WALL)
    //     mvprintw(y, (COLS/2), '|');
    //     else if (toDisplay[i][j] == PLAYER)
    //     mvprintw(y, (COLS/2), 'P');
    //     else if (toDisplay[i][j] == GHOST)
    //     mvprintw(y, (COLS/2), 'A');
    //     else if (toDisplay[i][j] == POINT)
    //     mvprintw(y, (COLS/2), 'o');
    // }
    // }
    // refresh();
    // return;
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
            return ("./lib_arcade_nibbler.so");
        } else if (key == '\n' && color_s == 2) {
            return ("./lib_arcade_pacman.so");
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
