/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#pragma once

#include "IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include <map>
#include <memory>
#include <chrono>

class SFML : public IGraphic
{
    public:
        SFML();
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
        sf::RenderWindow _window;
        std::map<int, std::shared_ptr<GameObject>> _objects;
        std::size_t _height;
        std::size_t _width;
        bool keyreleased;
        Key lastkey;
};