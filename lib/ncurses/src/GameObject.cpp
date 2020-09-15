/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** GameObject
*/

#include "GameObject.hpp"
#include <fstream>
#include "ncurses.h"
#include <iostream>

GameObject::GameObject(const std::string &sprite, std::pair<int, int> pos)
{
    std::string line;
    std::ifstream file;
    file.open(sprite);

    if(!file.is_open()) {
        endwin();
        std::cerr << "Error : Loading " << sprite << std::endl;
        exit(84);
    }
    while (!file.eof()) {
        file >> line;
        this->_sprite = line.data()[0];
        break;
    }
    file.close();
    this->_pos = pos;
}

GameObject::GameObject(const GameObject &object)
{
    this->_sprite = object.getSprite();
}

void GameObject::move(std::pair<int, int> pos)
{
    this->_pos = pos;
}

const char &GameObject::getSprite() const
{
    return (const_cast<char &>(this->_sprite));
}

void GameObject::setSprite(const char &sprite)
{
    this->_sprite = sprite;
}

const std::pair<int, int> &GameObject::getPos() const
{
    return (const_cast<std::pair<int, int> &>(this->_pos));
}