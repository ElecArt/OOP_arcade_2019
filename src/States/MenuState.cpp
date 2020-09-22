/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** file
*/

#include "MenuState.hpp"
#include "GameState.hpp"
#include "IGraphic.hpp"
#include "StateMachine.hpp"
#include <iostream>

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

MenuState::MenuState( StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace) :
State{ machine, lib_graphic, replace }
{
    std::cout << "MenuState : ctor" << std::endl;
    machine.statetype = 1;
    m_machine._lib_game.reset();
    this->enter_gamedir();
    this->enter_graphicdir();
    int counter = 0;
    for (auto it = machine.list_libgraphic.begin();
    it != machine.list_libgraphic.end(); it++, counter++) {
        if (machine._currentgraphic.find(*it) != std::string::npos) {
            machine._currentgraphic = *it;
            machine._indexgraphic = counter;
        }
    }
    this->_windowopen = true;
    this->display_bar = true;
    this->initNext();
}

void MenuState::initNext()
{
    this->_lib_graphic->loadGameObject(-1, "resources/arrowleft",{(WIDTH / 2)
    - (52 / 2) - 400,((HEIGHT / 2) - (88 / 2) - 0)});
    this->_lib_graphic->loadGameObject(-2, "resources/arrow",{(WIDTH / 2) -
    (52 / 2) + 400,((HEIGHT / 2) - (88 / 2) - 0)});
    this->_lib_graphic->loadGameObject(-4, "resources/arrowleft",{(WIDTH / 2) -
    (52 / 2) - 400,(HEIGHT / 2) - (88 / 2) + 100});
    this->_lib_graphic->loadGameObject(-5, "resources/arrow",{(WIDTH / 2) -
    (52 / 2) + 400,(HEIGHT / 2) - (88 / 2) + 100});
    this->_lib_graphic->loadGameObject(-3, "resources/background",{0, 0});
    this->_lib_graphic->loadGameObject(-6, "resources/bar",{(WIDTH / 2) -
    (100 / 2),((HEIGHT / 2) - (88 / 2) - 0)});
    this->m_machine._indexgame = 0;
    this->m_machine._currentgame = this->m_machine.list_libgame[
    this->m_machine._indexgame];
    this->menuindex = 0;
    this->original_graphic = this->m_machine._currentgraphic;
    this->m_machine.fpslimit = 60;
}

MenuState::~MenuState()
{
    std::cout << "MenuState : dtor" << std::endl;
}

void MenuState::pause()
{
    std::cout << "MenuState Pause" << std::endl;
}

void MenuState::resume()
{
    std::cout << "MenuState Resume" << std::endl;
}

void MenuState::update()
{
    _fpscurrent = std::chrono::steady_clock::now();
    this->fps = 1000.f / std::chrono::duration_cast
    <std::chrono::milliseconds>(_fpscurrent - _fpsstart).count();
    if (this->menuindex == 0)
        this->checkKeyboard();
    if (this->_lib_graphic->isKeyPressed(Key::RIGHT))
        this->changeLastGame();
    if (this->_lib_graphic->isKeyPressed(Key::LEFT))
        this->changeNextGame();
    if (this->_lib_graphic->isKeyPressed(Key::UP)) {
        if (this->menuindex > 0)
            menuindex--;
    }
    if (this->_lib_graphic->isKeyPressed(Key::DOWN)) {
        if (this->menuindex < 2)
            menuindex++;
    }
    if (this->_lib_graphic->isKeyPressed(Key::ECHAP))
        m_machine.quit();
    this->checkSpecialkeys();
}

void MenuState::checkSpecialkeys()
{
    if (this->_lib_graphic->isKeyPressed(Key::ENTER)) {
        if (m_machine._currentgraphic != this->original_graphic) {
            m_machine._lib_graphic->closeWindow();
            m_machine._lib_loader = std::make_unique<DLLoader<IGraphic>>
            ("./lib/" + m_machine._currentgraphic);
            m_machine._lib_graphic = m_machine._lib_loader->getInstance();
            m_machine._lib_graphic->openWindow(WIDTH, HEIGHT, "Arcade");
            m_machine.run( StateMachine::build<GameState>( m_machine,
            m_machine._lib_graphic, true ));
            return;
        }
        m_next = StateMachine::build<GameState>(m_machine,
        this->_lib_graphic, true);
    }
    if (this->_lib_graphic->isKeyPressed(Key::ESP))
        m_next = StateMachine::build<ScoreState>(m_machine,
        this->_lib_graphic, true);
    if (this->_lib_graphic->isKeyPressed(Key::F1))
        m_next = StateMachine::build<HelpState>(m_machine,
        this->_lib_graphic, true);
}

void MenuState::changeLastGame()
{
    if (this->menuindex == 1) {
        if (this->m_machine._indexgame <
        this->m_machine.list_libgame.size() - 1)
            this->m_machine._indexgame++;
        else
            this->m_machine._indexgame = 0;
        this->m_machine._currentgame =
        this->m_machine.list_libgame[this->m_machine._indexgame];
    }
    if (this->menuindex == 2) {
        if (this->m_machine._indexgraphic
        < this->m_machine.list_libgraphic.size() - 1)
            this->m_machine._indexgraphic++;
        else
            this->m_machine._indexgraphic = 0;
        this->m_machine._currentgraphic =
        this->m_machine.list_libgraphic[this->m_machine._indexgraphic];
    }
}

void MenuState::changeNextGame()
{
    if (this->menuindex == 1) {
        if (this->m_machine._indexgame > 0)
            this->m_machine._indexgame--;
        else
            this->m_machine._indexgame =
            m_machine.list_libgame.size() - 1;
        this->m_machine._currentgame =
        this->m_machine.list_libgame[this->m_machine._indexgame];
    }
    if (this->menuindex == 2) {
        if (this->m_machine._indexgraphic > 0)
            this->m_machine._indexgraphic--;
        else
            this->m_machine._indexgraphic =
            m_machine.list_libgraphic.size() - 1;
        this->m_machine._currentgraphic =
        this->m_machine.list_libgraphic[this->m_machine._indexgraphic];
    }
}

void MenuState::checkKeyboard()
{
    if (this->_lib_graphic->isKeyPressed(Key::RETOUR)) {
        if (!this->m_machine._playername.empty())
            this->m_machine._playername.resize(
            this->m_machine._playername.size() - 1);
    }
    if (this->m_machine._playername.size() < 15) {
        this->checkKeyRangeFirst();
        this->checkKeyRangeSecond();
        if (this->_lib_graphic->isKeyPressed(Key::U))
            this->m_machine._playername += "U";
        if (this->_lib_graphic->isKeyPressed(Key::V))
            this->m_machine._playername += "V";
        if (this->_lib_graphic->isKeyPressed(Key::W))
            this->m_machine._playername += "W";
        if (this->_lib_graphic->isKeyPressed(Key::X))
            this->m_machine._playername += "X";
        if (this->_lib_graphic->isKeyPressed(Key::Y))
            this->m_machine._playername += "Y";
        if (this->_lib_graphic->isKeyPressed(Key::Z))
            this->m_machine._playername += "Z";
    }
}

void MenuState::checkKeyRangeFirst()
{
    if (this->_lib_graphic->isKeyPressed(Key::A))
        this->m_machine._playername += "A";
    if (this->_lib_graphic->isKeyPressed(Key::B))
        this->m_machine._playername += "B";
    if (this->_lib_graphic->isKeyPressed(Key::C))
        this->m_machine._playername += "C";
    if (this->_lib_graphic->isKeyPressed(Key::D))
        this->m_machine._playername += "D";
    if (this->_lib_graphic->isKeyPressed(Key::E))
        this->m_machine._playername += "E";
    if (this->_lib_graphic->isKeyPressed(Key::F))
        this->m_machine._playername += "F";
    if (this->_lib_graphic->isKeyPressed(Key::G))
        this->m_machine._playername += "G";
    if (this->_lib_graphic->isKeyPressed(Key::H))
        this->m_machine._playername += "H";
    if (this->_lib_graphic->isKeyPressed(Key::I))
        this->m_machine._playername += "I";
    if (this->_lib_graphic->isKeyPressed(Key::J))
        this->m_machine._playername += "J";
}

void MenuState::checkKeyRangeSecond()
{
    if (this->_lib_graphic->isKeyPressed(Key::K))
        this->m_machine._playername += "K";
    if (this->_lib_graphic->isKeyPressed(Key::L))
        this->m_machine._playername += "L";
    if (this->_lib_graphic->isKeyPressed(Key::M))
        this->m_machine._playername += "M";
    if (this->_lib_graphic->isKeyPressed(Key::N))
        this->m_machine._playername += "N";
    if (this->_lib_graphic->isKeyPressed(Key::O))
        this->m_machine._playername += "O";
    if (this->_lib_graphic->isKeyPressed(Key::P))
        this->m_machine._playername += "P";
    if (this->_lib_graphic->isKeyPressed(Key::Q))
        this->m_machine._playername += "Q";
    if (this->_lib_graphic->isKeyPressed(Key::R))
        this->m_machine._playername += "R";
    if (this->_lib_graphic->isKeyPressed(Key::S))
        this->m_machine._playername += "S";
    if (this->_lib_graphic->isKeyPressed(Key::T))
        this->m_machine._playername += "T";
}

void MenuState::draw()
{
    if (fps <= 2) {
        if (this->display_bar == true)
            this->display_bar = false;
        else if (this->display_bar == false)
            this->display_bar = true;
        _fpsstart = std::chrono::steady_clock::now();
    }
    this->_lib_graphic->displayGameObject(-3);
    this->_lib_graphic->displayGameObject(-1);
    this->_lib_graphic->displayGameObject(-2);
    this->_lib_graphic->displayGameObject(-4);
    this->_lib_graphic->displayGameObject(-5);
    if (this->display_bar == true && this->menuindex == 0) {
        this->_lib_graphic->displayGameObject(-6);
    }
    this->drawText();
}

void MenuState::drawText()
{
    this->_lib_graphic->displayText("Arcade","resources/pixel.ttf",
    {(WIDTH /2) - (551 / 2),(HEIGHT / 2) - (160 / 2) - 210 }, 160);
    this->_lib_graphic->displayText(this->m_machine._playername,
    "resources/pixel.ttf", {(WIDTH / 2) - ((28 * this->m_machine
    ._playername.length()) / 2),((HEIGHT / 2) - (48 / 2)) - 80}, 48);
    this->_lib_graphic->displayText(this->m_machine._currentgame,
    "resources/pixel.ttf", {(WIDTH / 2) - ((28 * this->m_machine
    ._currentgame.length()) / 2),((HEIGHT / 2) - (48 / 2)) - 0}, 48);
    this->_lib_graphic->displayText(this->m_machine._currentgraphic,
    "resources/pixel.ttf", {(WIDTH / 2) - ((28 * this->m_machine
    ._currentgraphic.length()) / 2),((HEIGHT / 2) - (48 / 2) + 100)}, 48);
    this->_lib_graphic->displayText("Press space to see score table.",
    "resources/pixel.ttf", {(WIDTH / 2) - ((14 * 31) / 2),((HEIGHT / 2)
    - (24 / 2) + 300)}, 24);
    this->_lib_graphic->displayText("Press F1 to see help informations.",
    "resources/pixel.ttf", {(WIDTH / 2) - ((14 * 34) / 2),((HEIGHT / 2)
    - (24 / 2) + 350)}, 24);
}

void MenuState::enter_gamedir()
{
    struct dirent **filenames;
    int count = scandir("./games", &filenames, nullptr, alphasort);

    if (count < 0) {
        std::cerr << "Directory empty" << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        struct dirent *entry;
        entry = filenames[i];
        std::string filename = entry->d_name;
        if (entry->d_type != DT_DIR)
            this->m_machine.list_libgame.push_back(filename);
        free (entry);
    }
}

void MenuState::enter_graphicdir()
{
    struct dirent **filenames;
    int count = scandir("./lib", &filenames, nullptr, alphasort);

    if (count < 0) {
        std::cerr << "Directory empty" << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        struct dirent *entry;
        entry = filenames[i];
        std::string filename = entry->d_name;
        if (entry->d_type != DT_DIR)
            this->m_machine.list_libgraphic.push_back(filename);
        free(entry);
    }
}