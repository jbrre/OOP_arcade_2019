/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Environment
*/

#include "Environment.hpp"

Environment::Environment()
{
}

Environment::~Environment()
{
    delete(_map);
    if (_sprites != nullptr)
        delete(_sprites);
    if (_events != nullptr)
        delete(_events);
}

void Environment::addEvent(std::string type, std::vector<float> values)
{
    Environment::event_t event;

    event.type = type;
    event.values = values;
    _events->push_back(event);
}

bool Environment::isEvent(std::string type, Environment::event_t *event) const
{
    for (auto i = _events->begin(); i != _events->end(); i ++) {
        if (type == i->type) {
            if (event != nullptr)
                *event = *i.base();
            _events->erase(i);
            return true;
        }
    }
    return false;
}