#ifndef BOARD_H
#define BOARD_H
#include "Head.h"
#include "Body.h"
#include "Tail.h"
#include "Background.h"
#include "Apple.h"
#include "Snake.h"

class Board
{
    public:
    sf::RenderWindow*                   board;//Board
    Board();
    bool                                isEmpty(const std::pair<int,int> &check);
    void                                drawBoard();//Board
    

    static const int                    windowX;//Board
    static const int                    windowY;//Board
    static const int                    tilesX;//Board
    static const int                    tilesY;//Board
    static const int                    tile_size;//Board
    Apple                               apple;//Board
    private:
    
    
    
    Background                          background;//Board
    std::vector<std::pair<int,int>>     emptyBoard;
    
};

#endif//BOARD_H