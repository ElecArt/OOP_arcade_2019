/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreState
*/

#ifndef SCORESTATE_HPP_
#define SCORESTATE_HPP_

#include "State.hpp"
#include "StateMachine.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "MenuState.hpp"
#include "DLLoader.hpp"
#include <chrono>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class StateMachine;

class ScoreState : public State
{
    public:
        ScoreState( StateMachine &game,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        ~ScoreState();
        void pause();
        void update();
        void resume();
        void draw();
        std::vector<std::string> split(const std::string &s, char delim);
    private:
        std::map<std::string, int> field;
        std::string _playername;
        std::string _score;
        std::pair<std::string, int> playerscore;
        std::vector<std::pair<std::string, int>> update_score;
        std::vector<std::string> splitted;
        bool _windowopen;
};

#endif /* !SCORESTATE_HPP_ */