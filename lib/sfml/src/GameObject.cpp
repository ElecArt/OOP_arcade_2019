/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(const std::string &sprite, std::pair<int, int> pos)
{
    this->_texture.loadFromFile(sprite);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setPosition(pos.first, pos.second);
}

GameObject::GameObject(const GameObject &object)
{
    this->_sprite = object.getSprite();
    this->_texture = object.getTexture();
}

void GameObject::move(std::pair<int, int> pos)
{
    this->_sprite.setPosition(pos.first, pos.second);
}

const sf::Sprite &GameObject::getSprite() const
{
    return (const_cast<sf::Sprite &>(this->_sprite));
}

void GameObject::setSprite(const sf::Sprite &sprite)
{
    this->_sprite = sprite;
}

const sf::Texture &GameObject::getTexture() const
{
    return (const_cast<sf::Texture &>(this->_texture));
}

void GameObject::setTexture(sf::Texture &texture)
{
    this->_texture = texture;
}