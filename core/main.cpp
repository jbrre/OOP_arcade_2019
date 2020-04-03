/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** main
*/

#include "core.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Core *arcade = nullptr;
    IGraphical *lib = nullptr;
    IGame *game = nullptr;

    if (ac != 2) {
        std::cerr << "Usage: ./arcade lib" << std::endl;
        return (84);
    }
    arcade = new Core(av[1]);
    lib = arcade->getGraphs();
    std::cout << lib->menu() << std::endl;
    // while (!arcade->getGame()->isGameOver()) {
    //     arcade->getGraphs()->display(arcade->getGame()->getGameMap());
    //     arcade->getGame()->action();
    // }
    delete arcade;
    return (0);
}