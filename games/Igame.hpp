/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Igame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "../core/environment/Environment.hpp"

enum square_status {
    EMPTY = 0,
    APPLE,
    SNAKE_HEAD,
    SNAKE_BODY
};

class IGame {
    protected:
        int _score;
        Environment *_env;
        std::vector<std::vector<square_status>> _gameMap;
    public:
        virtual int game() = 0;
        virtual std::map<std::string,Environment::sprite_t> *getSprites() = 0;
        virtual void action() = 0;
        virtual void setEnvironment(Environment *to_set) = 0;
        virtual bool isGameOver() const = 0;
        virtual int getScore() const = 0;
        virtual std::string getGameName() const = 0;
};

#endif /* !IGAME_HPP_ */
