/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "GameOverState.hpp"
#include <fstream>

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

GameOverState::GameOverState(StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace) :
State{machine, lib_graphic, replace}
{
    std::cout << "GameOverState : ctor" << std::endl;
    machine.statetype = 1;
    this->_lib_graphic->loadGameObject(14,
    "resources/background_gameover",{0, 0});
    std::ofstream out;
    out.open("score.ini", std::ios::app);
    out << this->m_machine._playername << "=" <<
    std::to_string(this->m_machine._score) << std::endl;
    this->_windowopen = true;
}

GameOverState::~GameOverState()
{
    std::cout << "GameOverState : dtor" << std::endl;
}

void GameOverState::pause()
{
    std::cout << "GameOverState Pause" << std::endl;
}

void GameOverState::update()
{
    if ((this->_windowopen = _lib_graphic->isWindowOpen()) == false)
        m_machine.quit();
    if (this->_lib_graphic->isKeyPressed(Key::ESP))
        m_next = StateMachine::build<ScoreState>( m_machine,
        this->_lib_graphic, true);
    if (this->_lib_graphic->isKeyPressed(Key::R))
        m_next = StateMachine::build<GameState>(m_machine,
       this->_lib_graphic, true);
}

void GameOverState::resume()
{
    std::cout << "ScoreState Resume" << std::endl;
}

void GameOverState::draw()
{
    this->_lib_graphic->displayGameObject(14);
    this->_lib_graphic->displayText("Game Over!", "resources/pixel.ttf",
    {((WIDTH / 2) - ((70 * 9) / 2)), ((HEIGHT / 2) - (120 / 2)) - 50}, 120);
    std::stringstream displayscore;
    displayscore << "Score: " << this->m_machine._score;
    this->_lib_graphic->displayText(displayscore.str(), "resources/pixel.ttf",
    {(WIDTH / 2) - ((28 * displayscore.str().length()) / 2),((HEIGHT / 2) -
    (48 / 2)) + 50}, 48);
    this->_lib_graphic->displayText(
    "Press space to see the score table or R to reload.",
    "resources/pixel.ttf", {(WIDTH / 2) - ((14 * 50) / 2),
    ((HEIGHT / 2) - (24 / 2) + 300)}, 24);
}