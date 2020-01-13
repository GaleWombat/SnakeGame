#include "Background.h"
#include <iostream>

void Background::set(const std::string &pathname)
{
    background_texture.loadFromFile(pathname);
    background_sprite.setTexture(background_texture);
    background_sprite.setScale(0.25,0.25);
    background_sprite.setScale(0.125,0.125);
    background_sprite.setOrigin(64,64);
}

void Background::drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant)
{
    background_sprite.setPosition(x_coordinant,y_coordinant);
    board->draw(background_sprite);
}