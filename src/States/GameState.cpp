/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "GameState.hpp"
#include "GameOverState.hpp"
#include "MenuState.hpp"
#include "IGraphic.hpp"
#include "StateMachine.hpp"
#include <iostream>
#include <string>
#include <thread>

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

GameState::GameState( StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace) :
State{machine, lib_graphic, replace}
{
    std::cout << "GameState Init with";
    machine.statetype = 0;
    m_machine._lib_game.reset();
    std::cout << machine._currentgame << std::endl;
    machine._game_loader = std::make_shared<DLLoader<IGame>>(
   "./games/" + machine._currentgame);
    machine._lib_game = machine._game_loader->getInstance();
    machine._lib_game->start(this->_lib_graphic);
    this->_lib_graphic->loadGameObject(-7,
    "resources/background_game",{0, 0});
    this->m_machine._score = 0;
    this->_windowopen = true;
    m_machine.fpslimit = 60;
}

GameState::~GameState()
{
    std::cout << "GameState : dtor" << std::endl;
}

void GameState::pause()
{
    std::cout << "GameState Pause" << std::endl;
}

void GameState::resume()
{
    std::cout << "GameState Resume" << std::endl;
}

void GameState::update()
{
    if (m_machine._lib_game->_gameover == true) {
        std::cout << "this->m_machine._score = " << this->m_machine._score <<
        std::endl;
        std::cout << "m_machine._lib_game->getScore() = " <<
        m_machine._lib_game->getScore() << std::endl;
        this->m_machine._score += m_machine._lib_game->getScore();
        m_next = StateMachine::build<GameOverState>( m_machine,
        this->_lib_graphic, true);
    }
    if (this->_lib_graphic->isKeyPressed(Key::ECHAP)) {
        this->m_machine._score += m_machine._lib_game->getScore();
        m_next = StateMachine::build<MenuState>( m_machine,
        this->_lib_graphic, true);
    }
    this->changeGame();
    if (this->_lib_graphic->isKeyPressed(Key::R)) {
        m_machine._lib_game.reset();
        m_next = StateMachine::build<GameState>(m_machine,
        this->_lib_graphic, true);
    }
}

void GameState::draw()
{
    this->_lib_graphic->clearWindow();
    this->_lib_graphic->displayGameObject(-7); m_machine._lib_game->resume();
    this->_lib_graphic->displayText("Name: " + this->m_machine._playername,
    "resources/pixel.ttf", {5, HEIGHT - (28 * 2) - 5},28);
    std::string score = std::to_string(m_machine._lib_game->getScore() +
    this->m_machine._score);
    this->_lib_graphic->displayText("Score: " + score,
        "resources/pixel.ttf", {5, HEIGHT - (28) - 5}, 28);
}

void GameState::changeGame()
{
    if (this->_lib_graphic->isKeyPressed(Key::LEFT) &&
    this->m_machine._indexgame > 0) {
        this->m_machine._indexgame--;
        this->m_machine._score += m_machine._lib_game->getScore();
        this->m_machine._currentgame =
        this->m_machine.list_libgame[this->m_machine._indexgame];
        m_next = StateMachine::build<GameState>(m_machine,
        this->_lib_graphic, true);
    }
    if (this->_lib_graphic->isKeyPressed(Key::RIGHT) &&
    this->m_machine._indexgame <
    this->m_machine.list_libgame.size() - 1) {
        this->m_machine._score += m_machine._lib_game->getScore();
        this->m_machine._indexgame++;
        this->m_machine._currentgame =
        this->m_machine.list_libgame[this->m_machine._indexgame];
        m_next = StateMachine::build<GameState>(m_machine, this->_lib_graphic,
        true);
    }
}