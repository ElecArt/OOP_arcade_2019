/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#pragma once

#include "IGameObject.hpp"

class GameObject : public IGameObject<const char &>
{
    public:
        GameObject() = default;
        GameObject(const std::string &sprite, std::pair<int, int> pos);
        GameObject(const GameObject &object);
        void move(std::pair<int, int> pos) override;
        const char &getSprite() const override;
        void setSprite(const char &sprite) override;
        const std::pair<int, int> &getPos() const;
    private:
        char _sprite;
        std::pair<int, int> _pos;
};