/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libsfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include "IGraphical.hpp"

class libSFML : public IGraphical {
    public:
        libSFML();
        ~libSFML();
        void display();
        std::string getLibName() const { return (_libName); };
        void setEnvironment(Environment *newEnv) { _env = newEnv; };
};

#endif /* !LIBSFML_HPP_ */
