/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Snake.hpp"

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

void Snake::Snake_move()
{
    for (int i = snake_size; i > 0; i--) {
        snake[i].x = snake[i-1].x;
	    snake[i].y = snake[i-1].y;
    }
    snake_body == 0 ? snake[0].y += 1 : 0;
    snake_body == 1 ? snake[0].x -= 1 : 0;
    snake_body == 2 ? snake[0].x += 1 : 0;
    snake_body == 3 ? snake[0].y -= 1 : 0;
	if ((snake[0].x == _food.first) && (snake[0].y == _food.second)) {
        _score += 4;
        speed -= 1;
        snake_size++; 
    	_food.first = rand() % 20;
        _food.second = rand() % 20;
    }
}

void Snake::Border()
{
    if (snake[0].x > 59) {
        std::cout << "GAME OVER" << std::endl;
        this->_gameover = true;
    }
    if (snake[0].y > 39) {
        std::cout << "GAME OVER" << std::endl;
        this->_gameover = true;
    }
    if (snake[0].x < 0.f) {
        std::cout << "GAME OVER" << std::endl;
        this->_gameover = true;
    }
    if (snake[0].y < 0.f) {
        std::cout << "GAME OVER" << std::endl;
        this->_gameover = true;
    }
}

void Snake::Touch_snakebody()
{
    for (int i = 1; i < 500; i++) {
        if (snake[0].x == 1 && snake[0].y == 1)
            continue;
        /*else if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            std::cout << "GAME OVER" << std::endl;
            gameover();
        }*/
    }
}

Snake::Snake()
{
    std::cout << "Game : Constructor of game!" << std::endl;
    this->_windowopen = true;
    srand(time(0));
    this->_score = 1;
    this->_gameover = false;
}

void Snake::start(std::shared_ptr<IGraphic> libgraphic)
{
    std::cout << "Game : start" << std::endl;
    this->_graphic = libgraphic;
    this->_graphic->removeGameObjects();
    this->_graphic->loadGameObject(0, "games/snake/asset/snake", {10, 10});
    this->_graphic->loadGameObject(1, "games/snake/asset/snake", {60, 60});
    _food.first = 20;
    _food.second = 20;
    snake[0].x = 10;
    snake[0].y = 10;
    this->_start = std::chrono::steady_clock::now();
}

void Snake::resume()
{
    //std::cout << "Game : resume" << std::endl;

    this->_current = std::chrono::steady_clock::now();

    this->_graphic->isKeyPressed(Key::Q) ? snake_body = 1 : 0;
    this->_graphic->isKeyPressed(Key::D) ?  snake_body = 2 : 0;
    this->_graphic->isKeyPressed(Key::Z) ? snake_body = 3 : 0;
    this->_graphic->isKeyPressed(Key::S) ? snake_body = 0 : 0;
    
    if (std::chrono::duration_cast<std::chrono::milliseconds> (this->_current - this->_start).count() > speed) {
        this->_start = std::chrono::steady_clock::now();
        Snake_move();
        Touch_snakebody();
        Border();
    }
    for (int i = 0; i < snake_size; i++) {
        this->_graphic->setGameObject(0, {snake[i].x, snake[i].y}, "");
        this->_graphic->displayGameObject(0);
    }
    this->_graphic->setGameObject(1, {_food.first, _food.second}, "");
    this->_graphic->displayGameObject(1);
}

int Snake::getScore() const
{
    return (this->_score);
}

extern "C" std::shared_ptr<IGame> entry()
{
    return std::make_shared<Snake>();
}