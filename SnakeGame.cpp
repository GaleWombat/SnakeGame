#include"SnakeGame.h"

int SnakeGame::score = 100;

const int timeDelay =  70;

void SnakeGame::ending()
{
    sf::Font end_font;
    sf::Event event1;
    bool wait = 0;
    end_font.loadFromFile("tiff/8-Bit Madness.ttf");
    std:: string points = std::to_string(score);
    std:: string score_text = "Your score: " + points;
    sf::Text press {"(Press any key to continue)", end_font, 20};
    sf::Text ending {"GAME OVER",end_font,48};
    sf::Text show_score{score_text,end_font,30};
    ending.setFillColor(sf::Color::White);
    show_score.setFillColor(sf::Color::White);
    press.setFillColor(sf::Color::White);
    ending.setPosition(Board::tilesX/2,Board::tilesY/2);
    show_score.setPosition(Board::windowX/2-102,Board::windowY/2-30);
    press.setPosition(Board::windowX/2-112,Board::windowY/2+10);
    board.board->draw(ending);
    board.board->draw(show_score);
    board.board->draw(press);
    board.board->display();
    while(wait == 0)
    {
        while (board.board->pollEvent(event1))
        {
            if (event1.type == sf::Event::KeyPressed) wait =  1;
            if (event1.type == sf::Event::Closed) wait =  1;
        }
    }

}

void SnakeGame::game()
{
    sf::RenderWindow window(sf::VideoMode(Board::windowX,Board::windowY),"Snake");
    board.board = &window;
    board.board->setMouseCursorVisible(true);
    board.board->setKeyRepeatEnabled(true);
    board.board->setMouseCursorVisible(false);
    sf::Keyboard input;
    sf::Event event;                                          // event handling end
    current_direction =     Direction::RIGHT;
    next_direction =        Direction::RIGHT;
    int waitTime,inner=0;
    sf::Clock clock;
    sf::Clock pressingClock;
    sf::Time cycleTime;
    sf::Time pressingTime;
    pressingClock.restart();
    for(int i=0;i<snake.snake_body.size();i++) direction_history.push_back(current_direction);
    
    while(board.board->isOpen())                                           // game loop
    {
        while (board.board->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)  
            {
                ending(); 
                board.board->close(); 
            }    // closing window
        }
        waitTime = (timeDelay - (0.0001 * (score < 500000 ? score : 500000)));
        if(pressingClock.getElapsedTime()>sf::milliseconds(waitTime+timeDelay)&&(input.isKeyPressed(sf::Keyboard::Up)||input.isKeyPressed(sf::Keyboard::W)))
            {
                if(current_direction!=Direction::DOWN) 
                {
                    next_direction = Direction::UP;
                    pressingClock.restart();
                }
            }
        else if(pressingClock.getElapsedTime()>sf::milliseconds(waitTime+timeDelay)&&(input.isKeyPressed(sf::Keyboard::Down)||input.isKeyPressed(sf::Keyboard::S)))
            {
                if(current_direction!=Direction::UP) 
                {
                    next_direction = Direction::DOWN;
                    pressingClock.restart();
                }
            }
        else if(pressingClock.getElapsedTime()>sf::milliseconds(waitTime+timeDelay)&&(input.isKeyPressed(sf::Keyboard::Right)||input.isKeyPressed(sf::Keyboard::D)))
            {
                if(current_direction!=Direction::LEFT) 
                {
                    next_direction = Direction::RIGHT;
                    pressingClock.restart();
                }
            }
        else if(pressingClock.getElapsedTime()>sf::milliseconds(waitTime+timeDelay)&&(input.isKeyPressed(sf::Keyboard::Left)||input.isKeyPressed(sf::Keyboard::A)))
            {
                if(current_direction!=Direction::RIGHT) 
                {
                    next_direction = Direction::LEFT;
                    pressingClock.restart();
                }
            }
        else if(pressingClock.getElapsedTime()>sf::milliseconds(waitTime+timeDelay))
        {
            next_direction=current_direction;
            pressingClock.restart();
        }

        if(clock.getElapsedTime() >= sf::milliseconds(waitTime))
        {
            inner++;
            snake.snakeMove(snake.setNewHead(current_direction,next_direction),direction_history,current_direction,next_direction);
            direction_history[0] = current_direction;
            current_direction = next_direction;
            if(snake.snake_body[0]==board.apple.position) {Snake::isEating = true;score+=1000;}
            score -= 1;
            clock.restart();
        }
        board.drawBoard();
        snake.drawSnake(next_direction,direction_history,board.board);
        board.board->display();
        if(!snake.alive) 
        {
            ending(); 
            board.board->close(); 
        }
    }
}