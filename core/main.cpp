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
    Core *game;

    if (ac != 2) {
        std::cerr << "Usage: ./arcade lib" << std::endl;
        return (84);
    }
    game = new Core(av[1]);
    delete game;
    return (0);
}