/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameObject
*/

#pragma once

#include <string>
#include <utility>
#include <map>

template<typename Sprite>
class IGameObject
{
    public:
        virtual ~IGameObject() = default;
        virtual void move(std::pair<int, int> pos) = 0;
        virtual Sprite getSprite() const = 0;
        virtual void setSprite(Sprite) = 0;
};
