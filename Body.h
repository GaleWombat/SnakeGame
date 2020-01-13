#ifndef BODY_H
#define BODY_H
#include "SnakeLayout.h"

class Body: public SnakeLayout
{
    public:
    void set(const std::string &pathname_body, const std::string &pathname_body_right, const std::string &pathname_body_left);
    void drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where);
    private:
    Direction last_direction;
    sf::Texture body_texture;
    sf::Texture body_right_texture;
    sf::Texture body_left_texture;
    sf::Sprite body_sprite;
    sf::Sprite body_right_sprite;
    sf::Sprite body_left_sprite;
};

#endif//BODY_H