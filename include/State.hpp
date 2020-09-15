/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include "IGraphic.hpp"
#include <vector>

class StateMachine;

class State
{
    public:
        State(StateMachine &machine,
        std::shared_ptr<IGraphic> lib_graphic, bool replace = true);
        virtual ~State() = 0;
        State(const State&) = delete;
        State &operator=(const State &) = delete;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        std::unique_ptr<State> next();
        bool isReplacing();
    protected:
        StateMachine &m_machine;
        std::shared_ptr<IGraphic> _lib_graphic;
        bool m_replacing;
        std::unique_ptr<State> m_next;
};

#endif // STATE_HPP