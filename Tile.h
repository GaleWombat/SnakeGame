#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

#ifndef DIRECTION_ENUM
#define DIRECUION_ENUM

enum class Direction{UP,DOWN,RIGHT,LEFT,NONE};

#endif//DIRECTION_ENUM

class Tile
{
    public:
    virtual void set(const std::string &pathname) = 0;
};

#endif//TILE_H