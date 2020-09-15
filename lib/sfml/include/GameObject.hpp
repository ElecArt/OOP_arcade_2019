/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#pragma once

#include "IGameObject.hpp"
#include <SFML/Graphics.hpp>

class GameObject : public IGameObject<const sf::Sprite &>
{
    public:
        GameObject() = default;
        GameObject(const std::string &sprite, std::pair<int, int> pos);
        GameObject(const GameObject &object);
        void move(std::pair<int, int> pos) override;
        const sf::Sprite &getSprite() const override;
        void setSprite(const sf::Sprite &sprite) override;
        const sf::Texture &getTexture() const;
        void setTexture(sf::Texture &texture);
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};
