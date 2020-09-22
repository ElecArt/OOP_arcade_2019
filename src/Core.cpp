/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"
#include "GameState.hpp"
#include <string>

#define HEIGHT 40
#define WIDTH 60

Core::Core(std::string libpath) : _libpath(libpath)
{
    std::cout << "Core : ctor" << std::endl;
    machine._currentgraphic = _libpath;
    machine.statetype = 1;
    machine._lib_loader = std::make_shared<DLLoader<IGraphic>>(this->_libpath);
    machine._lib_graphic = machine._lib_loader->getInstance();
    machine._lib_graphic->openWindow(WIDTH * 20, HEIGHT * 20, "Arcade");
    machine.run( StateMachine::build<MenuState>
    (machine,machine._lib_graphic,true));
}

Core::~Core()
{
    std::cout << "Core : dtor" << std::endl;
    machine.m_states.top().reset();
    machine._lib_game.reset();
    machine._lib_graphic.reset();
    machine._lib_loader.reset();
    machine._game_loader.reset();
    exit(0);
}

void Core::start()
{
    std::cout << "Core : starting with " << this->getLibPath() << std::endl;
    std::chrono::steady_clock::time_point _fpsstart;
    std::chrono::steady_clock::time_point _fpscurrent;

    while (machine._lib_graphic->isWindowOpen() == true &&
    machine.running() == true) {
        _fpscurrent = std::chrono::steady_clock::now();
        this->fps = 1000.f / std::chrono::duration_cast
        <std::chrono::milliseconds>(_fpscurrent - _fpsstart).count();
        machine.nextState();
        this->changelib();
        machine.update();
        if (fps <= machine.fpslimit) {
            machine.draw();
            machine._lib_graphic->displayText("FPS: " + std::to_string((int)
            fps),"games/snake/asset/segoeui.ttf", {5, 0},16);
            machine._lib_graphic->displayWindow();
            _fpsstart = std::chrono::steady_clock::now();
        }
    }
}

void Core::changelib()
{
    if (machine.statetype == 0) {
        if (machine._lib_graphic->isKeyPressed(Key::UP) &&
        machine._indexgraphic > 0)
            this->changePreviousLib();
        if (machine._lib_graphic->isKeyPressed(Key::DOWN) &&
        machine._indexgraphic < machine.list_libgraphic.size() - 1)
            this->changeNextLib();
    }
}

void Core::changePreviousLib()
{
    machine._indexgraphic--;
    machine._currentgraphic = machine.list_libgraphic[machine._indexgraphic];
    std::cout << "changing lib to " << machine._currentgraphic << std::endl;
    machine._lib_graphic->closeWindow();
    machine._lib_game.reset();
    machine._lib_graphic.reset();
    machine._lib_loader = std::make_unique<DLLoader<IGraphic>>
    ("./lib/" + machine._currentgraphic);
    machine._lib_graphic = machine._lib_loader->getInstance();
    machine._lib_graphic->openWindow(WIDTH * 20,
    HEIGHT * 20, "Arcade");
    machine.run( StateMachine::build<GameState>
    (machine, machine._lib_graphic, true));
}

void Core::changeNextLib()
{
    machine._indexgraphic++;
    machine._currentgraphic = machine.list_libgraphic[machine._indexgraphic];
    std::cout << "changing lib to " << machine._currentgraphic << std::endl;
    machine._lib_graphic->closeWindow();
    machine._lib_game.reset();
    machine._lib_graphic.reset();
    machine._lib_loader = std::make_unique<DLLoader<IGraphic>>
    ("./lib/" + machine._currentgraphic);
    machine._lib_graphic = machine._lib_loader->getInstance();
    machine._lib_graphic->openWindow(WIDTH * 20,
    HEIGHT * 20, "Arcade");
    machine.run( StateMachine::build<GameState>(machine,
    machine._lib_graphic, true ));
}
