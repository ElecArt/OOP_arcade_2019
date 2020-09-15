/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"
#include "IGraphic.hpp"
#include <memory>
#include <vector>
#include <chrono>

class Pacman : public IGame
{
    public:
        Pacman();
        void start(std::shared_ptr<IGraphic> graphic);
        void resume();
        int getScore() const;
        void displayTwo(char c, int i, int j);
        void displayThree(char c, int i, int j);
        void compute();
        void check_player_collision(char c);
        void ghost_AI_compute_1_next(int n, char c);
        void ghost_AI_compute_2_next(int n, char c);
        void ghost_AI_compute_3_next(int n, char c);
        void ghost_AI_compute_4_next(int n, char c);
    private:
        void move_player();
        void ghost_move(std::vector<std::string> Map);
        void display();
        void player();
        void display_ghosts();
        void player_collision(std::vector<std::string> Map);
        void check_death();
        void win();
        void ghost_AI_compute_1(int n);
        void ghost_AI_compute_2(int n);
        void ghost_AI_compute_3(int n);
        void ghost_AI_compute_4(int n);
        void AI_core_1();
        void AI_core_2();
        void AI_core_3();
        void AI_core_4();
        int a;
        int b;
        int c;
        int d;
        int direction;
        std::pair<int, int> _player;
        std::pair<int, int> _ghost1;
        std::pair<int, int> _ghost2;
        std::pair<int, int> _ghost3;
        std::pair<int, int> _ghost4;
        std::pair<int, int> _food;
        std::pair <int, int> _score_pos;
        std::shared_ptr<IGraphic> _graphic;
        int _score;
        bool _windowopen;
        float speed = 170;
        std::chrono::steady_clock::time_point _start;
        std::chrono::steady_clock::time_point _current;
        std::pair<int, int> _pos;
};

#endif /* !PACMAN_HPP_ */