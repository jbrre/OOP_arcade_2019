/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** main_test
*/

#include "./include/snake.hpp"

int main(int ac, char **av)
{
    srand(time(NULL));
    Snake zizi(nullptr);
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.placeApple();
    zizi.printMap();
    return (0);
}