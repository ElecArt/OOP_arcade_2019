/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** include
*/

#ifndef GAMETEST_HPP_
#define GAMETEST_HPP_

#include "IGame.hpp"
#include "IGraphic.hpp"
#include <memory>
#include <iostream>
#include <chrono>

class Snake : public IGame
{
    public:
        Snake();
        void start(std::shared_ptr<IGraphic> graphic);
        void resume();
        int getScore() const;
        void Border();
        void Snake_move();
        void Touch_snakebody();
    private:
        std::shared_ptr<IGraphic> _graphic;
        std::chrono::steady_clock::time_point _start;
        std::chrono::steady_clock::time_point _current;
        bool _windowopen;
        float speed = 100;
        int snake_body;
        int snake_size = 4;
        struct Snake_tab {
            int x;
            int y;
        } snake[500];
        std::pair<int, int> _food;
        int _score;
};

#endif /* GAMETEST_HPP */