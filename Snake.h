#ifndef SNAKE_H
#define SNAKE_H

#include "Head.h"
#include "Body.h"
#include "Tail.h"
#include "Board.h"

class Snake
{
    public:
    static bool                         isEating;
    static bool                         alive;
    std::vector<std::pair<int,int>>     snake_body;
    std::pair<int,int>                  setNewHead(const Direction& current_direction, const Direction& next_direction);
    void                                snakeMove(std::pair<int,int> next_head_position, std::vector<Direction>& direction_history,const Direction& current_direction, const Direction& next_direction);
    Snake();
    
    bool                                isSnake(const std::pair<int,int> &placing);
    void                                drawSnake(const Direction& next_direction, std::vector<Direction>& direction_history, sf::RenderWindow* board);
    Direction                           onTurn(int snake_body_index, const Direction& next_direction, std::vector<Direction>& direction_history);
    Head                                head_layout;
    Body                                body_layout;
    Tail                                tail_layout;

    

    static bool                         isTurning;
};

#endif//SNAKE_H