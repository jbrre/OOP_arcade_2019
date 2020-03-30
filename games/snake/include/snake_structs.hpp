/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** snake_structs
*/

#ifndef SNAKE_STRUCTS_HPP_
#define SNAKE_STRUCTS_HPP_

#define MAP_SIZE 17

enum square_status {
    EMPTY = 0,
    APPLE,
    SNAKE_HEAD,
    SNAKE_BODY
};

enum direction {
    RIGHT,
    LEFT,
    UP,
    DOWN,
};

struct pos_t {
    int x;
    int y;
};

typedef struct pos_t pos_s;

#endif /* !SNAKE_STRUCTS_HPP_ */
