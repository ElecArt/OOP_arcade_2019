/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef OOP_ARCADE_2019_GAMESTATE_HPP
#define OOP_ARCADE_2019_GAMESTATE_HPP

#include "State.hpp"
#include "IGraphic.hpp"
#include <chrono>
#include <vector>
#include "IGame.hpp"
#include "DLLoader.hpp"
#include <dirent.h>

class StateMachine;

class GameState : public State
{
    public:
        GameState( StateMachine &game,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        ~GameState();
        void pause();
        void resume();
        void update();
        void draw();
        void changeGame();
    private:
        bool _windowopen;
};

#endif //OOP_ARCADE_2019_GAMESTATE_HPP
