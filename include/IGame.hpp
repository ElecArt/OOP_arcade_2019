/*
** EPITECH PROJECT, 2020
** boostrap_arcade
** File description:
** IGame
*/

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "IGraphic.hpp"

class IGame
{
    public:
        virtual ~IGame() = default;
        virtual void start(std::shared_ptr<IGraphic>) = 0;
        virtual void resume() = 0;
        virtual int getScore() const = 0;
        bool _gameover;
};