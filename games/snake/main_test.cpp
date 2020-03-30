/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** main_test
*/

#include "./include/snake.hpp"
#include <iostream>

int main(int ac, char **av)
{
    srand(time(NULL));
    Snake zizi(nullptr);
    zizi.placeApple();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.setDirection(DOWN);
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    std::cout << std::endl << std::endl << std::endl;
    zizi.stepOnce();
    zizi.updateMap();
    zizi.printMap();
    return (0);
}