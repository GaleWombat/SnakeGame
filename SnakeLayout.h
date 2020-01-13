#ifndef SNAKELAYOUT_H
#define SNAKELAYOUT_H
#include "Tile.h"

enum class SnakeParts{HEAD,BODY,TAIL,TURN_RIGHT,TURN_LEFT,HEAD_RIGHT,HEAD_LEFT,TAIL_RIGHT,TAIL_LEFT};

class SnakeLayout

{
    public:
    virtual void set(const std::string &pathname_part1, const std::string &pathname_part2, const std::string &pathname_part3) = 0;
    virtual void drawOnBoard(sf::RenderWindow* board, const int &x_coordinant, const int &y_coordinant, SnakeParts which, Direction where) = 0;
};


#endif//SNAKELAYOUT_H