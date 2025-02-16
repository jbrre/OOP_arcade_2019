/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** snake
*/

#include "snake.hpp"
#include <iostream> // for debug

Snake::Snake()
{
    _gameMap.resize(MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++) {
        _gameMap[i].resize(MAP_SIZE);
        for (unsigned int j = 0; j < this->_gameMap[i].size(); j++)
            this->_gameMap[i][j] = EMPTY;
    }
    _snakePos.resize(4);
    this->_snakePos[0].x = 8;
    this->_snakePos[0].y = 8;
    this->_snakePos[1].x = 8;
    this->_snakePos[1].y = 7;
    this->_snakePos[2].x = 8;
    this->_snakePos[2].y = 6;
    this->_snakePos[3].x = 8;
    this->_snakePos[3].y = 5;
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
    for (unsigned int i = 0; i < this->_gameMap.size(); i++)
        for (unsigned int j = 0; j < this->_gameMap[i].size(); j++)
            if (this->_gameMap[i][j] == SNAKE_BODY || this->_gameMap[i][j] == SNAKE_HEAD)
                this->_gameMap[i][j] = EMPTY;
    this->_gameMap[this->_snakePos[0].x][this->_snakePos[0].y] = SNAKE_HEAD;
    for (unsigned int i = 1; i < this->_snakePos.size(); i++) {
        this->_gameMap[this->_snakePos[i].x][this->_snakePos[i].y] = SNAKE_BODY;
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

    if (y > 0 && this->_gameMap[x][y-1] == EMPTY) {
        to_push.x = x;
        to_push.y = y - 1;
        _snakePos.push_back(to_push);
    } else if (y < MAP_SIZE && this->_gameMap[x][y+1] == EMPTY) {
        to_push.x = x;
        to_push.y = y + 1;
        _snakePos.push_back(to_push);
    } else if (x > 0 && this->_gameMap[x-1][y] == EMPTY) {
        to_push.x = x - 1;
        to_push.y = y;
        _snakePos.push_back(to_push);
    } else if (x < MAP_SIZE && this->_gameMap[x+1][y] == EMPTY) {
        to_push.x = x + 1;
        to_push.y = y;
        _snakePos.push_back(to_push);
    }
    this->_score += 100;
    this->updateMap();
}

void Snake::checkDirection(void)
{
    if (_env->isEvent("KEY_UP") && _snakeDirection != DOWN)
        _snakeDirection = UP;
    else if (_env->isEvent("KEY_DOWN") && _snakeDirection != UP)
        _snakeDirection = DOWN;
    else if (_env->isEvent("KEY_RIGHT") && _snakeDirection != LEFT)
        _snakeDirection = RIGHT;
    else if (_env->isEvent("KEY_LEFT") && _snakeDirection != RIGHT)
        _snakeDirection = LEFT;
}

void Snake::printMap(void) // debug
{
    for (unsigned int i = 0; i < this->_gameMap.size(); i++)
    {
        for (unsigned int j = 0; j < this->_gameMap[i].size(); j++)
        {
            std::cout << this->_gameMap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Snake::placeApple()
{
    for (unsigned int i = 0; i < this->_gameMap.size(); i++)
        for (unsigned int j = 0; j < this->_gameMap[i].size(); j++)
            if (this->_gameMap[i][j] == APPLE)
                return;
    int i = 0;
    int j = 0;
    while (1) {
        i = rand() % MAP_SIZE;
        j = rand() % MAP_SIZE;
        if (this->_gameMap[i][j] == EMPTY) {
            this->_gameMap[i][j] = APPLE;
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
    this->placeApple();
    this->checkDirection();
    this->stepOnce();
    if (this->_gameMap[_snakePos[0].x][_snakePos[0].y] == APPLE)
        this->upgradeSize();
    this->updateMap();
    return;
}

bool Snake::isGameOver() const
{
    if (_snakePos[0].x < 0 || _snakePos[0].y < 0)
        return (true);
    if (_snakePos[0].x >= this->_gameMap.size() - 1 || _snakePos[0].y >= this->_gameMap.size())
        return (true);
    else if (_gameMap[_snakePos[0].x][_snakePos[0].y] == SNAKE_BODY)
        return (true);
    return (false);
}

extern "C"
{
    IGame *create_game()
    {
        return new Snake();
    }
}