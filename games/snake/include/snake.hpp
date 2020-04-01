/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "../IGame.hpp"
#include "snake_structs.hpp"

class Snake : public IGame {
    public:
        Snake(Environment *env);
        ~Snake() = default;
        int game();
        std::map<std::string,Environment::sprite_t> *getSprites();
        void action();
        void setEnvironment(Environment *toSet) {_env = toSet;};
        bool isGameOver() const;
        int getScore() const {return (_score);};
        std::string getGameName() const {return ("snake");};
        void stepOnce();
        void placeApple();
        void updateMap();
        void checkDirection();
        void upgradeSize();
        void printMap(); // debug function;
    private:
        std::vector<std::vector<square_status>> _snakeMap;
        std::vector<pos_s> _snakePos;
        direction _snakeDirection;
};

#endif /* !SNAKE_HPP_ */