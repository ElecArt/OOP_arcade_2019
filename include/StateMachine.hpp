/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <memory>
#include <stack>
#include <string>
#include <vector>
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "DLLoader.hpp"

class State;

class StateMachine
{
    public:
        StateMachine();
        void run( std::unique_ptr<State> state );
        void nextState();
        void lastState();
        void update();
        void draw();
        bool running() { return m_running; }
        void quit() { m_running = false; }
        template <typename T>
        static std::unique_ptr<T> build(StateMachine &machine,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        std::stack<std::unique_ptr<State>> m_states;
        std::shared_ptr<IGraphic> _lib_graphic;
        std::shared_ptr<DLLoader<IGraphic>> _lib_loader;
        std::shared_ptr<IGame> _lib_game;
        std::shared_ptr<DLLoader<IGame>> _game_loader;
        std::string _currentgame;
        int _indexgame;
        std::vector<std::string> list_libgame;
        std::string _currentgraphic;
        int _indexgraphic;
        std::vector<std::string> list_libgraphic;
        std::string _playername;
        int _score;
        int fpslimit;
        int statetype;
    private:
        bool m_resume;
        bool m_running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace)
{
    return std::unique_ptr<T>(new T(machine, lib_graphic, replace));
}

#endif // GAMEENGINE_HPP