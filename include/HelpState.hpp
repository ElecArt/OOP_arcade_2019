/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** HelpState
*/

#ifndef HELPSTATE_HPP_
#define HELPSTATE_HPP_

#include "State.hpp"
#include "StateMachine.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "MenuState.hpp"
#include <iostream>
#include <string>

class StateMachine;

class HelpState : public State {
    public:
        HelpState(StateMachine &game,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        ~HelpState();
        void pause();
        void update();
        void resume();
        void draw();
        void draw_two();
        void draw_three();
        void draw_four();
    private:
        bool _windowopen;
};

#endif /* !HELPSTATE_HPP_ */