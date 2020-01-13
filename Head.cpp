#include "Head.h"

void Head::set(const std::string &pathname_head, const std::string &pathname_head_right, const std::string &pathname_head_left)
{
    head_texture.loadFromFile(pathname_head);
    head_right_texture.loadFromFile(pathname_head_right);
    head_left_texture.loadFromFile(pathname_head_left);
    head_sprite.setTexture(head_texture);
    head_right_sprite.setTexture(head_right_texture);
    head_left_sprite.setTexture(head_left_texture);

    head_sprite.setScale(0.125,0.125);
    head_right_sprite.setScale(0.125,0.125);
    head_left_sprite.setScale(0.125,0.125);

    head_sprite.setOrigin(64,64);
    head_right_sprite.setOrigin(64,64);
    head_left_sprite.setOrigin(64,64);

    head_sprite.setRotation(90);
    head_right_sprite.setRotation(90);
    head_left_sprite.setRotation(90);

}

void Head::drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where)
{
    switch(which)
    {
        case SnakeParts::HEAD:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        head_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        head_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        head_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        head_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            head_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(head_sprite);
            break;
        case SnakeParts::HEAD_RIGHT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        head_right_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        head_right_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        head_right_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        head_right_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            head_right_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(head_right_sprite);
            break;
        case SnakeParts::HEAD_LEFT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        head_left_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        head_left_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        head_left_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        head_left_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            head_left_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(head_left_sprite);
            break;
        default:
            break;
    }
    if(where!=Direction::NONE)last_direction = where;
}