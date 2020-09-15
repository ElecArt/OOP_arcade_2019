/*
** EPITECH PROJECT, 2020
** boostrap_arcade
** File description:
** IGraphic
*/

#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "IGameObject.hpp"

enum Type
{
    Text,
    Image
};

enum Key
{
    ECHAP,
    A, B, C, E, F, G, H, I, J, K, L,
    M, N, P, T, U, V, W, X,
    Y,
    Z,
    S,
    Q,
    D,
    F1,
    ESP,
    SHIFT,
    O,
    R,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ENTER,
    RETOUR,
    NONE
};

class IGraphic
{
    public:
        virtual ~IGraphic() = default;
        virtual void openWindow(std::size_t height, std::size_t width,
        const std::string &name) = 0;
        virtual void closeWindow() = 0;
        virtual void loadGameObject(int tag, const std::string &sprite_path,
        std::pair<int, int> pos) = 0;
        virtual void displayGameObject(int tag) = 0;
        virtual void setGameObject(int tag, std::pair<int, int> pos, const
        std::string &sprite_path = "") = 0;
        virtual void removeGameObject(int tag) = 0;
        virtual void removeGameObjects() = 0;
        virtual void displayText(const std::string &text, const std::string
        &font, std::pair<int, int>  pos, size_t size = 1) = 0;
        virtual bool isKeyPressed(Key key) = 0;
        virtual bool isWindowOpen() = 0;
        virtual void clearWindow() = 0;
        virtual void displayWindow() = 0;
};