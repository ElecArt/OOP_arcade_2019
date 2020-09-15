/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Allegro
*/

#pragma once

#include "IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "GameObject.hpp"
#include <map>
#include <memory>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

class Allegro : public IGraphic
{

    struct AllegroFont {
        ALLEGRO_FONT *font;
        int size;
        std::string path;
    };

    public:
        Allegro();
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
        bool allIsKeyPressed(ALLEGRO_EVENT ev, int key);
    private:
        std::map<int, std::shared_ptr<GameObject>> _objects;
        std::size_t _height;
        std::size_t _width;
        ALLEGRO_DISPLAY *_window;
        std::vector<AllegroFont> fonts;
        ALLEGRO_EVENT_QUEUE *_queue;
        ALLEGRO_KEYBOARD_STATE _key;
        bool keyreleased;
        Key lastkey;
};