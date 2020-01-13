#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Tile.h"

class Background: public Tile
{
    public:
    void set(const std::string &pathname);
    void drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant);
    private:
    sf::Texture background_texture;
    sf::Sprite background_sprite;
};

#endif//BACKGROUND_H