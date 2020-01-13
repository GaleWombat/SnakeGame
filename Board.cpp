#include "Board.h"
#include <string>

const int Board::windowX =          800; 
const int Board::windowY =          640;
const int Board::tile_size =        16; 
const int Board::tilesX =           windowX / tile_size; //50 tiles
const int Board::tilesY =           windowY / tile_size; //40 tiles

Board::Board()
{
    
    background.set("images/background.png");
    apple.set("images/apple.png");
}

void Board::drawBoard()
{
    static std::pair<int, int> elonging;
    emptyBoard.clear();
    for(int i=1;i<tilesY;i++)
    {
        for(int j=1;j<tilesX;j++)
        {
            background.drawOnBoard(board,j*tile_size,i*tile_size);
            emptyBoard.push_back(std::make_pair(i,j));
        }
    }
    if(!Apple::applePlaced)
    {
            Apple::applePlaced=false;
            apple.drawOnBoard(board);
    }
    else apple.drawOnBoard(board);

}
bool Board::isEmpty(const std::pair<int,int>& check)
{
    for(auto &i : emptyBoard){if(check.first == i.first && check.second == i.second) return true;}
    return false;
}