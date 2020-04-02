/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libncurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include "IGraphical.hpp"

#define TERM_SIZE 100

class libNCurses : public IGraphical {
    public:
        libNCurses();
        ~libNCurses();
        void display(std::vector<std::vector<square_status>> toDisplay) const;
        std::string getLibName() const { return (_libName); };
        void setEnvironment(Environment *newEnv) { _env = newEnv; };
        void menu(void) const;
};

#endif /* !LIBNCURSES_HPP_ */
