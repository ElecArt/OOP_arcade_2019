/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#pragma once

#include "IGameObject.hpp"
#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

struct Sprite
{
    ALLEGRO_BITMAP *_sprite;
    std::pair<int, int> _pos;
};

class GameObject : public IGameObject<const Sprite &>
{
    public:
        GameObject() = default;
        GameObject(const std::string &sprite, std::pair<int, int> pos);
        GameObject(const GameObject &object);
        void move(std::pair<int, int> pos) override;
        const Sprite &getSprite() const override;
        void setSprite(const Sprite &sprite) override;
        const std::pair<int, int> &getPos() const;
    private:
        Sprite _sprite;
};
