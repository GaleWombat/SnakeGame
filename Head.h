#ifndef HEAD_H
#define HEAD_H
#include "SnakeLayout.h"

class Head: public SnakeLayout
{
    public:
    void set(const std::string &pathname_head, const std::string &pathname_head_right, const std::string &pathname_head_left);
    void drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where);
    private:
    Direction last_direction;
    sf::Texture head_texture;
    sf::Texture head_right_texture;
    sf::Texture head_left_texture;
    sf::Sprite head_sprite;
    sf::Sprite head_right_sprite;
    sf::Sprite head_left_sprite;
};

#endif//HEAD_H