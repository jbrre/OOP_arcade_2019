/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** pacman
*/

#include "pacman.hpp"
#include <iostream> // for debug

Pacman::Pacman()
{
    _score = 0;
    _gameMap = mapBase;
    _pacmanDirection = RIGHT;
    _pacmanPos.x = 4;
    _pacmanPos.y = 5;
}

int Pacman::game(void)
{
    return (0);
}

void Pacman::action()
{
    return;
}

bool Pacman::isGameOver() const
{
    return (false);
}

void Pacman::updateMap(void)
{
    if (isGameOver()) {
        std::cerr << "Error: tried update map while game over." << std::endl;
        return;
    }
    for (unsigned int i = 0; i < _gameMap.size(); i++)
        for (unsigned int j = 0; j < _gameMap[i].size(); j++)
            if (this->_gameMap[i][j] == PLAYER)
                this->_gameMap[i][j] = EMPTY;
    if (this->_gameMap[_pacmanPos.x][_pacmanPos.y] == POINT)
        this->_score += 100;
    this->_gameMap[_pacmanPos.x][_pacmanPos.y] = PLAYER;
}

void Pacman::stepOnce()
{
    if (isGameOver()) {
        std::cerr << "Error: tried to step while game over." << std::endl;
        return;
    }
    if (_pacmanDirection == RIGHT && _gameMap[_pacmanPos.x][_pacmanPos.y + 1] != WALL)
        this->_pacmanPos.y += 1;
    else if (_pacmanDirection == LEFT && _gameMap[_pacmanPos.x][_pacmanPos.y - 1] != WALL)
        this->_pacmanPos.y -= 1;
    else if (_pacmanDirection == DOWN && _gameMap[_pacmanPos.x + 1][_pacmanPos.y] != WALL)
        this->_pacmanPos.x += 1;
    else if (_pacmanDirection == UP && _gameMap[_pacmanPos.x - 1][_pacmanPos.y] != WALL)
        this->_pacmanPos.x -= 1;
}

std::map<std::string,Environment::sprite_t> *Pacman::getSprites()
{
    return (nullptr);
}

void Pacman::printMap(void) // debug
{
    for (unsigned int i = 0; i < this->_gameMap.size(); i++)
    {
        for (unsigned int j = 0; j < this->_gameMap[i].size(); j++)
        {
            std::cout << this->_gameMap[i][j] << "";
        }
        std::cout << std::endl;
    }
}

extern "C"
{
    IGame *create_game()
    {
        return new Pacman();
    }
}