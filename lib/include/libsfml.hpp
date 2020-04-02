/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** libsfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "IGraphical.hpp"

class libSFML : public IGraphical {
    public:
        libSFML();
        ~libSFML();
        void display(std::vector<std::vector<square_status>> toDisplay) const;
        std::string getLibName() const { return (_libName); };
        void setEnvironment(Environment *newEnv) { _env = newEnv; };
        void menu(void) const {};
    private:
        sf::RenderWindow window;
};

#endif /* !LIBSFML_HPP_ */
