#ifndef TAIL_H
#define TAIL_H
#include "SnakeLayout.h"

class Tail: public SnakeLayout
{
    public:
    void set(const std::string &pathname_tail, const std::string &pathname_tail_right, const std::string &pathname_tail_left);
    void drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where);
    private:
    Direction last_direction;
    sf::Texture tail_texture;
    sf::Texture tail_right_texture;
    sf::Texture tail_left_texture;
    sf::Sprite tail_sprite;
    sf::Sprite tail_right_sprite;
    sf::Sprite tail_left_sprite;
};

#endif//TAIL_H