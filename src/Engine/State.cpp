/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "State.hpp"
#include "IGraphic.hpp"

State::State(StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace)
: m_machine{ machine }
, _lib_graphic { lib_graphic }
, m_replacing{ replace }
{
}

State::~State()
{
}

std::unique_ptr<State> State::next()
{
    return std::move(m_next);
}

bool State::isReplacing()
{
    return m_replacing;
}