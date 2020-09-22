/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "StateMachine.hpp"
#include "State.hpp"
#include <iostream>
#include <memory>

StateMachine::StateMachine()
: m_resume{ false }
, m_running{ false }
{
    std::cout << "StateMachine : ctor" << std::endl;
}

void StateMachine::run(std::unique_ptr<State>state)
{
    m_running = true;
    m_states.push(std::move(state));
}

void StateMachine::nextState()
{
    std::unique_ptr<State> temp;

    if (m_states.empty() == false) {
        temp = m_states.top()->next();
        if (temp != nullptr) {
            if (temp->isReplacing()) {
                m_states.top().reset();
                m_states.pop();
            }
            else
                m_states.top()->pause();
            m_states.push( std::move(temp));
        }
    }
}

void StateMachine::update()
{
    m_states.top()->update();
}

void StateMachine::draw()
{
    m_states.top()->draw();
}