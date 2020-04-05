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

enum square_status {
    EMPTY = 0,
    APPLE,
    SNAKE_HEAD,
    SNAKE_BODY,
    WALL,
    PLAYER,
    GHOST,
    POINT
};

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
            std::pair<float, float> origin;
            size_t spriteID;
            std::string color;
            float length;
            float width;
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

        std::map<std::string, entity_t> *getMap() { return _map; };
        void addOrUpdateEntity(const entity_t entity);
        void removeEntity(const std::string name);
        void setSprites(std::map<std::string, sprite_t> *sprites) { _sprites = sprites; };
        std::map<std::string, sprite_t> *getSprites() { return _sprites; };
        
        std::vector<event_t> *getEvents() { return _events; };
        bool isEvent(const std::string type, event_t *event = nullptr);
        void addEvent(const std::string type, const std::vector<float> values = std::vector<float>(0, 0));

    protected:
    private:
        std::map<std::string, entity_t> *_map = new std::map<std::string, entity_t>();
        std::map<std::string, sprite_t> *_sprites = nullptr;
        std::vector<event_t> *_events = new std::vector<event_t>;
};

#endif /* !ENVIRONMENT_HPP_ */