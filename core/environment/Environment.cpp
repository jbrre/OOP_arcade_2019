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

void Environment::addEvent(const std::string type, const std::vector<float> values)
{
    Environment::event_t event;

    event.type = type;
    event.values = values;
    _events->push_back(event);
}

void Environment::addOrUpdateEntity(const Environment::entity_t entity)
{
    if (_map->find(entity.name) == _map->end())
        _map->insert(std::pair<std::string, Environment::entity_t>(entity.name, entity));
    else {
        _map->at(entity.name).type = entity.type;
        _map->at(entity.name).text = entity.text;
        _map->at(entity.name).x = entity.x;
        _map->at(entity.name).y = entity.y;
        _map->at(entity.name).origin = entity.origin;
        _map->at(entity.name).spriteID = entity.spriteID;
        _map->at(entity.name).color = entity.color;
        _map->at(entity.name).length = entity.length;
        _map->at(entity.name).width = entity.width;
    }
}

void Environment::removeEntity(const std::string name)
{
    if (_map->find(name) != _map->end())
        _map->erase(name);
}

bool Environment::isEvent(const std::string type, Environment::event_t *event)
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