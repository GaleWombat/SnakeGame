#include "Snake.h"

bool Snake::isEating =      false;
bool Snake::isTurning =     false;
bool Snake::alive =         true;

Snake::Snake()
{
    head_layout.set("images/head.png","images/head_right.png","images/head_left.png");
    body_layout.set("images/body.png","images/turn_right.png","images/turn_left.png");
    tail_layout.set("images/tail.png","images/tail_right.png","images/tail_left.png");
    snake_body.push_back(std::pair<int,int>(Board::tilesX/2,Board::tilesY/2));
    snake_body.push_back(std::pair<int,int>(Board::tilesX/2-1,Board::tilesY/2));                  // initializing snake
    snake_body.push_back(std::pair<int,int>(Board::tilesX/2-2,Board::tilesY/2));
    snake_body.push_back(std::pair<int,int>(Board::tilesX/2-3,Board::tilesY/2));
}

bool Snake::isSnake(const std::pair<int,int> &placing)
{
    if (placing==snake_body[0]||placing==snake_body[1])
    {
        for(auto i=2; i<snake_body.size(); i++)
        {
            if(placing==snake_body[i]) return true;
        }
        return false;
    }
    else 
    {
        for(auto &i : snake_body){if(placing.first == i.first && placing.second == i.second) return true;}
        return false;
    }
    return false;
}

std::pair<int,int> Snake::setNewHead(const Direction& current_direction, const Direction& next_direction)
{
    static std::pair<int,int> next_head_position = snake_body[0];
    if(next_direction!=Direction::NONE)
    {
        switch(next_direction)
        {
        case Direction::RIGHT: 
            if(next_head_position.first+1 <= Board::tilesX) 
            {   
                if(current_direction == next_direction)next_head_position.first ++;
                else isTurning = true;
            }
            else alive = false; 
            break;
        case Direction::LEFT:
            if(next_head_position.first-1 >= 1)
            {   
                if(current_direction == next_direction)next_head_position.first --;
                else isTurning = true;
            }
            else alive = false;
            break;
        case Direction::UP: 
            if(next_head_position.second-1 >= 1)
            {   
                if(current_direction == next_direction)next_head_position.second --;
                else isTurning = true;
            } 
            else alive = false;
            break;
        case Direction::DOWN:
            if(next_head_position.second+1 <= Board::tilesY)
            {   
                if(current_direction == next_direction)next_head_position.second ++;
                else isTurning = true;
            }
            else alive = false;
            break;
        default:
            break;
        }
    }
    return next_head_position;
}
void Snake::snakeMove(std::pair<int,int> next_head_position, std::vector<Direction>& direction_history,const Direction& current_direction, const Direction& next_direction)
{
    // std::cout<<"NEW HEAD: "<<next_head_position.first<<", "<<next_head_position.second<<std::endl;
    if(!isTurning)
    {
        for(int i = snake_body.size();i>=1;i--)
        {
            snake_body[i] = snake_body[i-1];
            direction_history[i] = direction_history[i-1];
        }

        snake_body[0] = next_head_position;
            
    }    
    if(isTurning) 
    {
        isTurning = false;
    }
    if(isEating)
    {
        Apple::applePlaced = false;
        auto elonging = snake_body[snake_body.size()-1];
        snake_body.push_back(elonging);
        isEating = false;
    }
    if(next_head_position.first==0||next_head_position.first==Board::tilesX||next_head_position.second==0||next_head_position.second==Board::tilesY||isSnake(next_head_position))
    {
        alive = false;
    }
    
}

void Snake::drawSnake(const Direction& next_direction, std::vector<Direction>& direction_history, sf::RenderWindow* board)
{
    if(onTurn(0,next_direction, direction_history)==Direction::NONE)head_layout.drawOnBoard(board,snake_body[0].first*Board::tile_size,snake_body[0].second*Board::tile_size,SnakeParts::HEAD,next_direction);
    else if(onTurn(0, next_direction, direction_history)==Direction::LEFT)head_layout.drawOnBoard(board,snake_body[0].first*Board::tile_size,snake_body[0].second*Board::tile_size,SnakeParts::HEAD_LEFT,direction_history[0]);
    else if(onTurn(0, next_direction, direction_history)==Direction::RIGHT)head_layout.drawOnBoard(board,snake_body[0].first*Board::tile_size,snake_body[0].second*Board::tile_size,SnakeParts::HEAD_RIGHT,direction_history[0]);
    for (int i=1;i<snake_body.size()-1;i++)
    {
        if(onTurn(i, next_direction, direction_history)==Direction::NONE)body_layout.drawOnBoard(board,snake_body[i].first*Board::tile_size,snake_body[i].second*Board::tile_size,SnakeParts::BODY,direction_history[i-1]);
        else if(onTurn(i, next_direction, direction_history)==Direction::LEFT)body_layout.drawOnBoard(board,snake_body[i].first*Board::tile_size,snake_body[i].second*Board::tile_size,SnakeParts::TURN_LEFT,direction_history[i-1]);
        else if(onTurn(i, next_direction, direction_history)==Direction::RIGHT)body_layout.drawOnBoard(board,snake_body[i].first*Board::tile_size,snake_body[i].second*Board::tile_size,SnakeParts::TURN_RIGHT,direction_history[i-1]);
    }
    

        if(onTurn(snake_body.size()-1,next_direction, direction_history)==Direction::NONE)tail_layout.drawOnBoard(board,snake_body[snake_body.size()-1].first*Board::tile_size,snake_body[snake_body.size()-1].second*Board::tile_size,SnakeParts::TAIL,direction_history[snake_body.size()-1]);
        else if(onTurn(snake_body.size()-1,next_direction, direction_history)==Direction::LEFT)tail_layout.drawOnBoard(board,snake_body[snake_body.size()-1].first*Board::tile_size,snake_body[snake_body.size()-1].second*Board::tile_size,SnakeParts::TAIL_LEFT,direction_history[snake_body.size()-1]);
        else if(onTurn(snake_body.size()-1,next_direction, direction_history)==Direction::RIGHT)tail_layout.drawOnBoard(board,snake_body[snake_body.size()-1].first*Board::tile_size,snake_body[snake_body.size()-1].second*Board::tile_size,SnakeParts::TAIL_RIGHT,direction_history[snake_body.size()-1]);
}

Direction Snake::onTurn(int snake_body_index, const Direction& next_direction, std::vector<Direction>& direction_history)
{
    Direction heading_direction, tailing_direction;
    if(snake_body_index==0) {heading_direction = next_direction; tailing_direction = direction_history[snake_body_index];}
    else {heading_direction = direction_history[snake_body_index]; tailing_direction = direction_history[snake_body_index-1];}

    if(tailing_direction==heading_direction) return Direction::NONE;
    else if(
        (tailing_direction==Direction::RIGHT&&heading_direction==Direction::UP)||
        (tailing_direction==Direction::DOWN&&heading_direction==Direction::RIGHT)||
        (tailing_direction==Direction::LEFT&&heading_direction==Direction::DOWN)||
        (tailing_direction==Direction::UP&&heading_direction==Direction::LEFT)
    )return Direction::LEFT;
    else if(
        (tailing_direction==Direction::RIGHT&&heading_direction==Direction::DOWN)||
        (tailing_direction==Direction::DOWN&&heading_direction==Direction::LEFT)||
        (tailing_direction==Direction::LEFT&&heading_direction==Direction::UP)||
        (tailing_direction==Direction::UP&&heading_direction==Direction::RIGHT)
    )return Direction::RIGHT;
}