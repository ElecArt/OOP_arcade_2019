/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** HelpState
*/

#include "HelpState.hpp"

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

HelpState::HelpState(StateMachine &machine, std::shared_ptr<IGraphic>
lib_graphic, bool replace) : State{machine, lib_graphic, replace}
{
    std::cout << "HelpState : ctor" << std::endl;

    this->_lib_graphic->loadGameObject(-7, "resources/background_game",{0, 0});
    this->_windowopen = true;
}

HelpState::~HelpState()
{
    std::cout << "HelpState : dtor" << std::endl;
}

void HelpState::pause()
{
    std::cout << "HelpState Pause" << std::endl;
}

void HelpState::update()
{
    if (this->_lib_graphic->isKeyPressed(Key::ECHAP))
        m_next = StateMachine::build<MenuState>(
        m_machine, this->_lib_graphic, true);
}

void HelpState::resume()
{
    std::cout << "HelpState Resume" << std::endl;
}

void HelpState::draw()
{
    if ((this->_windowopen = _lib_graphic->isWindowOpen()) == false)
        m_machine.quit();
    _lib_graphic->clearWindow();
    _lib_graphic->displayGameObject(-7);
    this->_lib_graphic->displayText("Help!","resources/pixel.ttf",
        {(WIDTH / 2 / 2 + 170), (HEIGHT / 2) - (100 / 2) - 300}, 100);
    this->_lib_graphic->displayText("Move Up       Z",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250),
    (HEIGHT / 2) - (100 / 2) - 100}, 25);
    this->_lib_graphic->displayText("Move Down     S",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250),
    (HEIGHT / 2) - (100 / 2) - 50}, 25);
    this->_lib_graphic->displayText("Move Left     Q",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250),
    (HEIGHT / 2) - (100 / 2) - 0}, 25);
    this->_lib_graphic->displayText("Move Right    D",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250), (HEIGHT / 2)
    - (100 / 2) + 50}, 25);
    this->draw_two();
}

void HelpState::draw_two()
{
    this->_lib_graphic->displayText("restart game  R",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250), (HEIGHT / 2)
    - (100 / 2) + 100}, 25);
    this->_lib_graphic->displayText("Start game  Enter",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 - 250), (HEIGHT / 2)
    - (100 / 2) + 150}, 25);
    this->_lib_graphic->displayText
    ("Switch Game/Graphics library to the left     Left arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) - 100}, 25);
    this->_lib_graphic->displayText
    ("Switch Game/Graphics library to the right    Right arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) - 50}, 25);
    this->_lib_graphic->displayText("Go to the previous option\
                    Up arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) - 0}, 25);
    this->draw_three();
}

void HelpState::draw_three()
{
    this->_lib_graphic->displayText("Go to the next option  \
                      Down arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) + 50}, 25);
    this->_lib_graphic->displayText("Back to Menu           \
                      Esc",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) + 100}, 25);
    this->_lib_graphic->displayText("Exit                   \
                      Esc * 2",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) + 150}, 25);
    this->_lib_graphic->displayText("Previous game          \
                      Left arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) + 200}, 25);
    this->_lib_graphic->displayText("Next game              \
                      Right arrow",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 50), (HEIGHT / 2)
    - (100 / 2) + 250}, 25);
    this->draw_four();
}

void HelpState::draw_four()
{
    this->_lib_graphic->displayText("Game Production Team",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 10), (HEIGHT / 2)
    - (100 / 2) + 310}, 50);
    this->_lib_graphic->displayText("Valentin CHARBONNIER",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 60), (HEIGHT / 2)
    - (100 / 2) + 400}, 23);
    this->_lib_graphic->displayText("Jinyang ZOU",
    "resources/pixel.ttf", {(WIDTH / 2 / 2 + 390), (HEIGHT / 2)
    - (100 / 2) + 400}, 23);
}