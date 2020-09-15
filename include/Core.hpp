/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#pragma once

#include "include.hpp"
#include "IGraphic.hpp"
#include "IGame.hpp"
#include "DLLoader.hpp"
#include <vector>
#include <string>
#include <dirent.h>
#include <chrono>
#include "StateMachine.hpp"
#include "MenuState.hpp"

class Core
{
    public:
        Core(std::string libpath);
        ~Core();
        void start();
        std::string getLibPath() { return (this->_libpath); }
        void changelib();
        void changePreviousLib();
        void changeNextLib();
    private:
        std::string _libpath;
        StateMachine machine;
        double fps;
};