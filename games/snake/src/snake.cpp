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
    _snakePos.resize(3);
    this->_snakePos[0].x = 8;
    this->_snakePos[0].y = 8;
    this->_snakePos[1].x = 8;
    this->_snakePos[1].y = 7;
    this->_snakePos[2].x = 8;
    this->_snakePos[2].y = 6;
    this->updateMap();
}

int Snake::game(void)
{
    return (0);
}

void Snake::updateMap(void)
{
    if (isGameOver()) {
        std::cerr << "Error: tried update map while game over." << std::endl;
        return;
    }
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < this->_snakeMap[i].size(); j++)
            if (this->_snakeMap[i][j] == SNAKE_BODY || this->_snakeMap[i][j] == SNAKE_HEAD)
                this->_snakeMap[i][j] = EMPTY;
    this->_snakeMap[this->_snakePos[0].x][this->_snakePos[0].y] = SNAKE_HEAD;
    for (int i = 1; i < this->_snakePos.size(); i++) {
        this->_snakeMap[this->_snakePos[i].x][this->_snakePos[i].y] = SNAKE_BODY;
    }
}

void Snake::stepOnce(void)
{
    int x_save = this->_snakePos[0].x;
    int y_save = this->_snakePos[0].y;

    if (isGameOver()) {
        std::cerr << "Error: tried to step game over." << std::endl;
        return;
    }
    if (_snakeDirection == RIGHT)
        this->_snakePos[0].y += 1;
    else if (_snakeDirection == LEFT)
        this->_snakePos[0].y -= 1;
    else if (_snakeDirection == DOWN)
        this->_snakePos[0].x += 1;
    else if (_snakeDirection == UP)
        this->_snakePos[0].x -= 1;
    for (int i = this->_snakePos.size(); i > 1; i--) {
        this->_snakePos[i].x = this->_snakePos[i-1].x;
        this->_snakePos[i].y = this->_snakePos[i-1].y;
    }
    this->_snakePos[1].x = x_save;
    this->_snakePos[1].y = y_save;
}

void Snake::upgradeSize(void)
{
    pos_s to_push;
    int x = this->_snakePos[this->_snakePos.size() - 1].x;
    int y = this->_snakePos[this->_snakePos.size() - 1].y;

    if (y > 0 && this->_snakeMap[x][y-1] == EMPTY) {
        to_push.x = x;
        to_push.y = y - 1;
        _snakePos.push_back(to_push);
    } else if (y < MAP_SIZE && this->_snakeMap[x][y+1] == EMPTY) {
        to_push.x = x;
        to_push.y = y + 1;
        _snakePos.push_back(to_push);
    } else if (x > 0 && this->_snakeMap[x-1][y] == EMPTY) {
        to_push.x = x - 1;
        to_push.y = y;
        _snakePos.push_back(to_push);
    } else if (x < MAP_SIZE && this->_snakeMap[x+1][y] == EMPTY) {
        to_push.x = x + 1;
        to_push.y = y;
        _snakePos.push_back(to_push);
    }
    this->updateMap();
}

void Snake::setDirection(direction newDir)
{
    if (_snakeDirection == DOWN && newDir == UP)
        return;
    if (_snakeDirection == UP && newDir == DOWN)
        return;
    if (_snakeDirection == LEFT && newDir == RIGHT)
        return;
    if (_snakeDirection == RIGHT && newDir == LEFT)
        return;
    _snakeDirection = newDir;
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
    if (_snakePos[0].x < 0 || _snakePos[0].y < 0)
        return (true);
    if (_snakePos[0].x >= MAP_SIZE || _snakePos[0].y >= MAP_SIZE)
        return (true);
    else if (_snakeMap[_snakePos[0].x][_snakePos[0].y] == SNAKE_BODY)
        return (true);
    return (false);
}