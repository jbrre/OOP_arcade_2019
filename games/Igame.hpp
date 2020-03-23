/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** Igame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "../core/environment/Environment.hpp"

class IGame {
    protected:
        int _score;
        Environment *_env;
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
