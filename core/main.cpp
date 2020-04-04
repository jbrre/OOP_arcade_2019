/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** main
*/

#include "core.hpp"
#include <iostream>
#include <unistd.h>

int main(int ac, char **av)
{
    Environment general;
    Core *arcade = nullptr;
    IGraphical *lib = nullptr;
    IGame *game = nullptr;

    if (ac != 2) {
        std::cerr << "Usage: ./arcade lib" << std::endl;
        return (84);
    }
    arcade = new Core(av[1]);
    lib = arcade->getGraphs();
    arcade->loadGame(lib->menu());
    game = arcade->getGame();
    arcade->setEnv(&general);
    game->setEnvironment(&general);
    lib->setEnvironment(&general);
    lib->display(game->getGameMap());
    while (!(game->isGameOver())) {
        game->action();
        lib->display(game->getGameMap());
        usleep(LOOP_DELAY);
    }
    delete arcade;
    return (0);
}