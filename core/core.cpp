/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** core
*/

#include <iostream>
#include <dlfcn.h>
#include "core/core.hpp"

Core::Core(std::string libName)
{
    void *libChecker;

    this->_sharedLib = dlopen(libName.c_str(), RTLD_LAZY);
    if (!this->_sharedLib) {
        std::cerr << "dlopen: " << dlerror() << std::endl;
        exit(84); // to replace with appropriate exception
    }
    libChecker = dlsym(this->_sharedLib, "create_lib");
    if (!libChecker) {
        std::cerr << "dlsym: " << dlerror() << std::endl;
        exit(84); // to replace with appropriate exception
    }
    this->_graphs = (libMaker)libChecker;
}

Core::~Core()
{
    dlclose(this->_sharedLib);
}

void Core::loadGame(std::string gameName)
{
    void *gameChecker;

    this->_sharedLib = dlopen(gameName.c_str(), RTLD_LAZY);
    if (!this->_sharedLib) {
        std::cerr << "dlopen: " << dlerror() << std::endl;
        exit(84); // to replace with appropriate exception
    }
    gameChecker = dlsym(this->_sharedLib, "create_game");
    if (!gameChecker) {
        std::cerr << "dlsym: " << dlerror() << std::endl;
        exit(84); // to replace with appropriate exception
    }
    this->_game = (IGame*)gameChecker;
}