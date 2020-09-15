/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef MenuState_HPP
#define MenuState_HPP

#include "State.hpp"
#include "ScoreState.hpp"
#include "HelpState.hpp"
#include "IGraphic.hpp"
#include <chrono>
#include <vector>
#include <dirent.h>

class StateMachine;

class MenuState : public State
{
    public:
        MenuState( StateMachine &game,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true );
        ~MenuState();
        void pause();
        void resume();
        void update();
        void draw();
        void enter_gamedir();
        void enter_graphicdir();
        void initNext();
        void checkKeyboard();
        void changeLastGame();
        void changeNextGame();
        void checkSpecialkeys();
        void drawText();
        void checkKeyRangeFirst();
        void checkKeyRangeSecond();
    private:
        int menuindex;
        bool _windowopen;
        std::chrono::steady_clock::time_point _fpsstart;
        std::chrono::steady_clock::time_point _fpscurrent;
        bool display_bar;
        double fps;
        std::string original_graphic;
};

#endif // MenuState_HPP