/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef OOP_ARCADE_2019_GAMEOVERSTATE_HPP
#define OOP_ARCADE_2019_GAMEOVERSTATE_HPP

#include "State.hpp"
#include "StateMachine.hpp"
#include "ScoreState.hpp"
#include <sstream>
#include "GameState.hpp"

class StateMachine;

class GameOverState  : public State
{
    public:
        GameOverState(StateMachine &game,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        ~GameOverState();
        void pause();
        void update();
        void resume();
        void draw();
    private:
        bool _windowopen;
};

#endif //OOP_ARCADE_2019_GAMEOVERSTATE_HPP
