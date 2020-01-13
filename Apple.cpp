#include "Apple.h"
#include <iostream>

bool Apple::applePlaced = false;

void Apple::set(const std::string &pathname) //Ustawienie początkowe jabłka (tekstura itd.)
{
    apple_texture.loadFromFile(pathname);
    apple_sprite.setTexture(apple_texture);
    apple_sprite.setScale(0.125,0.125);
    apple_sprite.setOrigin(64,64);
}

void Apple::drawOnBoard(sf:: RenderWindow* board) //Rysowanie jabłka w oknie wskazanym wskaźnikiem oraz umieszczanie jabłka na tablicy, gdy nie jest umieszczone
{
    srand(time(NULL));
    static std::pair<int,int> tempApple;
    if(!applePlaced)
    {
        tempApple.first = rand()%49+1;
        tempApple.second = rand()%39+1;
        position = tempApple;
        applePlaced = true;
    }
    apple_sprite.setPosition(tempApple.first*16,tempApple.second*16);
    board->draw(apple_sprite);
}