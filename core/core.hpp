/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "core/environment/Environment.hpp"
#include "games/IGame.hpp"
#include "lib/IGraphical.hpp"

#define LOOP_DELAY 500000

class Core {
    private:
        Environment *_env;
        libMaker _graphs;
        gameMaker _game;
        void *_sharedLib;
        void *_sharedGame;
    public:
        Core(std::string libName);
        ~Core();
        void setEnv(Environment *toSet);
        void setGraph(IGraphical *toSet);
        void loadGame(std::string gameName);
        Environment *getEnv() const { return _env; };
        IGraphical *getGraphs() const { return this->_graphs(); };
        IGame *getGame() const { return this->_game(); };
};

#endif /* !CORE_HPP_ */
