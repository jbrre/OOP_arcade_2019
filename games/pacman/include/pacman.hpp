/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "pacman_structs.hpp"

class Pacman : public IGame {
    public:
        Pacman(Environment *env);
        ~Pacman() = default;
        int game();
        std::map<std::string,Environment::sprite_t> *getSprites();
        void action();
        void setEnvironment(Environment *toSet) {_env = toSet;};
        bool isGameOver() const;
        int getScore() const {return (_score);};
        std::string getGameName() const {return ("pacman");};
        void stepOnce();
        void updateMap();
        void checkDirection();
        void printMap(); // debug function;
    private:
        pos_s _pacmanPos;
        direction _pacmanDirection;
};

#endif /* !PACMAN_HPP_ */