#include "Body.h"

void Body::set(const std::string &pathname_body, const std::string &pathname_body_right, const std::string &pathname_body_left)
{
    body_texture.loadFromFile(pathname_body);
    body_right_texture.loadFromFile(pathname_body_right);
    body_left_texture.loadFromFile(pathname_body_left);
    body_sprite.setTexture(body_texture);
    body_right_sprite.setTexture(body_right_texture);
    body_left_sprite.setTexture(body_left_texture);

    body_sprite.setScale(0.125,0.125);
    body_right_sprite.setScale(0.125,0.125);
    body_left_sprite.setScale(0.125,0.125);

    body_sprite.setOrigin(64,64);
    body_right_sprite.setOrigin(64,64);
    body_left_sprite.setOrigin(64,64);

    body_sprite.setRotation(90);
    body_right_sprite.setRotation(90);
    body_left_sprite.setRotation(90);

}

void Body::drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where)
{
    switch(which)
    {
        case SnakeParts::BODY:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        body_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        body_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        body_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        body_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            body_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(body_sprite);
            break;
        case SnakeParts::TURN_RIGHT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        body_right_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        body_right_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        body_right_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        body_right_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            body_right_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(body_right_sprite);
            break;
        case SnakeParts::TURN_LEFT:
            switch(where)
            {
                case Direction::RIGHT:
                    {
                        body_left_sprite.setRotation(90);
                    }
                    break;
                case Direction::LEFT:
                    {
                        body_left_sprite.setRotation(270);
                    }
                    break;
                case Direction::DOWN:
                    {
                        body_left_sprite.setRotation(180);
                    }
                    break;
                case Direction::UP:
                    {
                        body_left_sprite.setRotation(0);
                    }
                    break;
                default:
                    break;
            }
            body_left_sprite.setPosition(x_coordinant,y_coordinant);
            board->draw(body_left_sprite);
            break;
        default:
            break;
    
    }
    if(where!=Direction::NONE)last_direction = where;   
}