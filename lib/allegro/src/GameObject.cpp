/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(const std::string &sprite, std::pair<int, int> pos)
{
    this->_sprite._sprite = al_load_bitmap(sprite.c_str());
    this->_sprite._pos = pos;
}

GameObject::GameObject(const GameObject &object)
{
    this->_sprite = object.getSprite();
}

void GameObject::move(std::pair<int, int> pos)
{
    this->_sprite._pos = pos;
}

const Sprite &GameObject::getSprite() const
{
    return (const_cast<Sprite &>(this->_sprite));
}

void GameObject::setSprite(const Sprite &sprite)
{
    this->_sprite = sprite;
}

const std::pair<int, int> &GameObject::getPos() const
{
    return (const_cast<std::pair<int, int> &>(this->_sprite._pos));
}