#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include "Snake.h"
#include "Board.h"


class SnakeGame
{
    public:
    void                                game();
    private:
    void                                ending();//SnakeGame
    static int                          score;//SnakeGame

    Direction                           current_direction;//SnakeGame
    Direction                           next_direction;//SnakeGame
    std::vector<Direction>              direction_history;//SnakeGame

    // std::vector<std::pair<int,int>>     snake_body;//Snake
    Snake snake;
    Board board;
    
    

};

#endif//SNAKEGAME_H