/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
{
    keyreleased = false;
}

void SFML::openWindow(std::size_t width, std::size_t height,
const std::string &name)
{
    this->_window.create(sf::VideoMode(width, height), name + " - SFML");
    this->_width = width;
    this->_height = height;
}

void SFML::closeWindow()
{
    this->_window.close();
}

void SFML::loadGameObject(int tag, const std::string &sprite_path,
std::pair<int, int> pos)
{
    std::shared_ptr<GameObject> object =
    std::make_shared<GameObject>(sprite_path + ".png", pos);
    this->_objects.insert(std::pair<int,
    std::shared_ptr<GameObject>>(tag, object));
}

void SFML::displayGameObject(int tag)
{
    this->_window.draw(this->_objects[tag]->getSprite());
}

void SFML::setGameObject(int tag, std::pair<int, int> pos,
const std::string &sprite_path)
{
    (void)sprite_path;
    pos.first *= 20;
    pos.second *= 20;
    this->_objects[tag]->move(pos);
}

void SFML::removeGameObject(int tag)
{
    this->_objects.erase(tag);
}

void SFML::removeGameObjects()
{
    this->_objects.clear();
}

void SFML::displayText(const std::string &text,
const std::string &font, std::pair<int, int>  pos, size_t size)
{
    sf::Text sftext;
    sf::Font sffont;

    if (!(sffont.loadFromFile(font)))
        exit(84);
    sftext.setFont(sffont);
    sftext.setString(text);
    sftext.setCharacterSize(size);
    sftext.setPosition(pos.first, pos.second);
    sftext.setFillColor(sf::Color::White);
    this->_window.draw(sftext);
}

bool SFML::isKeyPressed(Key key)
{
    sf::Keyboard::Key sfmlkey;

    switch (key) {
        case ECHAP:
            sfmlkey = sf::Keyboard::Escape;
            break;
        case F1:
            sfmlkey = sf::Keyboard::F1;
            break;
        case A:
            sfmlkey = sf::Keyboard::A;
            break;
        case B:
            sfmlkey = sf::Keyboard::B;
            break;
        case C:
            sfmlkey = sf::Keyboard::C;
            break;
        case E:
            sfmlkey = sf::Keyboard::E;
            break;
        case F:
            sfmlkey = sf::Keyboard::F;
            break;
        case G:
            sfmlkey = sf::Keyboard::G;
            break;
        case H:
            sfmlkey = sf::Keyboard::H;
            break;
        case I:
            sfmlkey = sf::Keyboard::I;
            break;
        case J:
            sfmlkey = sf::Keyboard::J;
            break;
        case K:
            sfmlkey = sf::Keyboard::K;
            break;
        case L:
            sfmlkey = sf::Keyboard::L;
            break;
        case M:
            sfmlkey = sf::Keyboard::M;
            break;
        case N:
            sfmlkey = sf::Keyboard::N;
            break;
        case O:
            sfmlkey = sf::Keyboard::O;
            break;
        case P:
            sfmlkey = sf::Keyboard::P;
            break;
        case T:
            sfmlkey = sf::Keyboard::T;
            break;
        case U:
            sfmlkey = sf::Keyboard::U;
            break;
        case V:
            sfmlkey = sf::Keyboard::V;
            break;
        case W:
            sfmlkey = sf::Keyboard::W;
            break;
        case X:
            sfmlkey = sf::Keyboard::X;
            break;
        case Y:
            sfmlkey = sf::Keyboard::Y;
            break;
        case Z:
            sfmlkey = sf::Keyboard::Z;
            break;
        case S:
            sfmlkey = sf::Keyboard::S;
            break;
        case Q:
            sfmlkey = sf::Keyboard::Q;
            break;
        case D:
            sfmlkey = sf::Keyboard::D;
            break;
        case ESP:
            sfmlkey = sf::Keyboard::Space;
            break;
        case R:
            sfmlkey = sf::Keyboard::R;
            break;
        case LEFT:
            sfmlkey = sf::Keyboard::Left;
            break;  
        case RIGHT:
            sfmlkey = sf::Keyboard::Right;
            break;  
        case UP:
            sfmlkey = sf::Keyboard::Up;
            break;  
        case DOWN:
            sfmlkey = sf::Keyboard::Down;
            break;
        case RETOUR:
            sfmlkey = sf::Keyboard::BackSpace;
            break;
        case ENTER:
            sfmlkey = sf::Keyboard::Enter;
            break;
        default:
            sfmlkey = sf::Keyboard::Escape;
            break;
    }
    if (keyreleased == false) {
        if (key != lastkey && sf::Keyboard::isKeyPressed(sfmlkey) == true) {
            lastkey = key;
            keyreleased = true;
            return (true);
        }
    }
    return (false);
}

bool SFML::isWindowOpen()
{
    sf::Event event;

    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return (false);
        if (event.type == sf::Event::KeyReleased) {
            lastkey = Key::NONE;
            keyreleased = true;
        }
        if (event.type == sf::Event::KeyPressed)
            keyreleased = false;
    }
    return (true);
}

void SFML::clearWindow()
{
    this->_window.clear(sf::Color::Black);
}

void SFML::displayWindow()
{
    this->_window.display();
}

extern "C" std::shared_ptr<IGraphic> entry()
{
    return std::make_shared<SFML>();
}