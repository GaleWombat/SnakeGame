#include "Tail.h"

void Tail::set(const std::string &pathname_tail, const std::string &pathname_tail_right, const std::string &pathname_tail_left)
{
    tail_texture.loadFromFile(pathname_tail);
    tail_right_texture.loadFromFile(pathname_tail_right);
    tail_left_texture.loadFromFile(pathname_tail_left);
    tail_sprite.setTexture(tail_texture);
    tail_right_sprite.setTexture(tail_right_texture);
    tail_left_sprite.setTexture(tail_left_texture);

    tail_sprite.setScale(0.125,0.125);
    tail_right_sprite.setScale(0.125,0.125);
    tail_left_sprite.setScale(0.125,0.125);

    tail_sprite.setOrigin(64,64);
    tail_right_sprite.setOrigin(64,64);
    tail_left_sprite.setOrigin(64,64);

    tail_sprite.setRotation(90);
    tail_right_sprite.setRotation(90);
    tail_left_sprite.setRotation(90);

}

void Tail::drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where)
{
    switch(which)
    {
        case SnakeParts::TAIL:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        tail_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        tail_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        tail_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        tail_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            tail_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(tail_sprite);
            break;
        case SnakeParts::TAIL_RIGHT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        tail_right_sprite.setRotation(0);
                    }
                    break;
                case Direction::LEFT:
                    {
                        tail_right_sprite.setRotation(180);
                    }
                    break;
                case Direction::DOWN:
                    {
                        tail_right_sprite.setRotation(90);
                    }
                    break;
                case Direction::UP:
                    {
                        tail_right_sprite.setRotation(270);
                    }
                    break;
                default:
                    break;
            }
            tail_right_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(tail_right_sprite);
            break;
        case SnakeParts::TAIL_LEFT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        tail_left_sprite.setRotation(180);
                    }
                    break;
                case Direction::LEFT:
                    {
                        tail_left_sprite.setRotation(0);
                    }
                    break;
                case Direction::DOWN:
                    {
                        tail_left_sprite.setRotation(270);
                    }
                    break;
                case Direction::UP:
                    {
                        tail_left_sprite.setRotation(90);
                    }
                    break;
                default:
                    break;
            }
            tail_left_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(tail_left_sprite);
            break;
        default:
            break;
    }
    if(where!=Direction::NONE)last_direction = where;
}