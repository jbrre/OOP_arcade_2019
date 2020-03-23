/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Environment
*/

#ifndef ENVIRONMENT_HPP_
#define ENVIRONMENT_HPP_

#include <string>
#include <vector>
#include <map>

class Environment {
    public:
        Environment();
        ~Environment();

        typedef struct entity_s {
            std::string name;
            std::string type;
            std::string text; // Only usefull for text entities
            size_t x;
            size_t y;
            size_t spriteID;
            std::string color;
            size_t length;
            size_t width;
        } entity_t;

        typedef struct sprite_s {
            std::string type;
            std::vector<std::string> sprites;
            std::vector<std::string> imgs;
        } sprite_t;

        typedef struct event_s {
            std::string type;
            std::vector<float> values;
        } event_t;

        std::map<std::string, entity_t> *getMap() const { return _map; };
        void setSprites(std::map<std::string, sprite_t> *sprites) { _sprites = sprites; };
        std::map<std::string, sprite_t> *getSprites() const { return _sprites; };
        
        std::vector<event_t> *getEvents() const { return _events; };
        bool isEvent(std::string type, event_t *event = nullptr) const;
        void addEvent(std::string type, std::vector<float> values = std::vector<float>(0, 0));

    protected:
    private:
        std::map<std::string, entity_t> *_map = new std::map<std::string, entity_t>();
        std::map<std::string, sprite_t> *_sprites = nullptr;
        std::vector<event_t> *_events = new std::vector<event_t>;
};

#endif /* !ENVIRONMENT_HPP_ */