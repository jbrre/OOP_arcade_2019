/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include "../core/environment/Environment.hpp"

class IGraphical {
    protected:
        Environment *_env;
    public:
        virtual void display() = 0;
        virtual std::string getLibName() const = 0;
        virtual void setEnvironment(Environment *newEnv) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
