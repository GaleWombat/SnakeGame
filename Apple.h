#ifndef APPLE_H
#define APPLE_H
#include "Tile.h"
#include <random>

class Apple: public Tile //Klasa dziedzicząca po
{
    public:
    std::pair<int,int> position;
    void set(const std::string &pathname);
    void drawOnBoard(sf::RenderWindow* board);
    static bool applePlaced;
    private:
    
    sf::Texture apple_texture;
    sf::Sprite apple_sprite;
    std::default_random_engine generator;
};

#endif//APPLE_H