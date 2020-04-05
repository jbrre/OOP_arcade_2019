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
    std::cout << "Opening graphical lib..." << std::endl;
    arcade = new Core(av[1]);
    std::cout << "Graphical lib open !" << std::endl;
    lib = arcade->getGraphs();
    arcade->loadGame(lib->menu());
    std::cout << "Opening game lib..." << std::endl;
    game = arcade->getGame();
    std::cout << "Game lib open !" << std::endl;
    arcade->setEnv(&general);
    game->setEnvironment(&general);
    lib->setEnvironment(&general);
    lib->display(game->getGameMap());
    while (!(game->isGameOver())) {
        game->action();
        lib->display(game->getGameMap());
        usleep(LOOP_DELAY);
    }
    std::cout << "Game over. Score :" << game->getScore() << std::endl;
    delete arcade;
    return (0);
}