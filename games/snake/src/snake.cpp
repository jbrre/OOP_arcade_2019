/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** snake
*/

#include "../include/snake.hpp"
#include <iostream> // for debug

Snake::Snake(Environment *toSet)
{
    _env = toSet;
    _snakeMap.resize(MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++) {
        _snakeMap[i].resize(MAP_SIZE);
        for (int j = 0; j < this->_snakeMap[i].size(); j++)
            this->_snakeMap[i][j] = EMPTY;
    }
    this->_snakeMap[8][8] = SNAKE_HEAD;
    this->_snakeMap[8][7] = SNAKE_BODY;
    this->_snakeMap[8][6] = SNAKE_BODY;
}

int Snake::game(void)
{
    return (0);
}

void Snake::printMap(void) // debug
{
    for (int i = 0; i < this->_snakeMap.size(); i++)
    {
        for (int j = 0; j < this->_snakeMap[i].size(); j++)
        {
            std::cout << this->_snakeMap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Snake::placeApple()
{
    for (int i = 0; i < this->_snakeMap.size(); i++)
        for (int j = 0; j < this->_snakeMap[i].size(); j++)
            if (this->_snakeMap[i][j] == APPLE)
                return;
    int i = 0;
    int j = 0;
    while (1) {
        i = rand() % MAP_SIZE;
        j = rand() % MAP_SIZE;
        if (this->_snakeMap[i][j] == EMPTY) {
            this->_snakeMap[i][j] = APPLE;
            return;
        }
    }
}

std::map<std::string,Environment::sprite_t> *Snake::getSprites()
{
    return (nullptr);
}

void Snake::action()
{
    return;
}

bool Snake::isGameOver() const
{
    return (true);
}