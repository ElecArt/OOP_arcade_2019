/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#pragma once

#include "IGraphic.hpp"
#include "ncurses.h"
#include "GameObject.hpp"
#include <map>
#include <memory>

class Ncurses : public IGraphic
{
    public:
        Ncurses();
        void openWindow(std::size_t height, std::size_t width, const std::string &name);
        void closeWindow();
        void loadGameObject(int tag, const std::string &sprite_path, std::pair<int, int> pos);
        void displayGameObject(int tag);
        void setGameObject(int tag, std::pair<int, int> pos, const std::string &sprite_path = "");
        void removeGameObject(int tag);
        void removeGameObjects();
        void displayText(const std::string &text, const std::string &font, std::pair<int, int>  pos, size_t size = 1);
        bool isKeyPressed(Key key);
        bool isWindowOpen();
        void clearWindow();
        void displayWindow();
    private:
        WINDOW	*_window;
        int _char;
        std::map<int, std::shared_ptr<GameObject>> _objects;
};