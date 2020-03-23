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

class Core {
    private:
        Environment *_env;
        IGraphical *_graphs;
        IGame *_game;
        void *_sharedLib;
        void *_sharedGame;
    public:
        Core(std::string libName);
        ~Core();
        void setEnv(Environment *toSet);
        void setGraph(IGraphical *toSet);
        void setGame(IGraphical *toSet);
        Environment *getEnv() const { return _env; };
        IGraphical *getGraphs() const { return _graphs; };
        IGame *getGame() const { return _game; };
        void loadGame(std::string gameName);
};

#endif /* !CORE_HPP_ */
