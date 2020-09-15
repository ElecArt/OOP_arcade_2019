/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Allegro
*/

#include "Allegro.hpp"

Allegro::Allegro()
{
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
}

void Allegro::openWindow(std::size_t width, std::size_t height, const
std::string &name)
{
    this->_width = width;
    this->_height = height;
    this->_window = al_create_display(width, height);
    al_set_window_title(this->_window,
    std::string(name + " - Allegro").c_str());
    this->_queue = al_create_event_queue();
    al_register_event_source(this->_queue,
    al_get_keyboard_event_source());
    al_register_event_source(this->_queue,
    al_get_display_event_source
    (this->_window));
}

void Allegro::closeWindow()
{
    al_destroy_display(this->_window);
    al_uninstall_keyboard();
    al_uninstall_system();
    this->_window = nullptr;
}

void Allegro::loadGameObject(int tag,
const std::string &sprite_path, std::pair<int, int> pos)
{
    std::shared_ptr<GameObject> object =
    std::make_shared<GameObject>(sprite_path + ".png", pos);
    this->_objects.insert(std::pair<int,
    std::shared_ptr<GameObject>>(tag, object));
}

void Allegro::displayGameObject(int tag)
{
    al_draw_bitmap(this->_objects[tag]->getSprite()._sprite,
    this->_objects[tag]->getPos().first,
    this->_objects[tag]->getPos().second, 0);
}

void Allegro::setGameObject(int tag,
std::pair<int, int> pos, const std::string &sprite_path)
{
    (void)sprite_path;
    pos.first *= 20;
    pos.second *= 20;
    this->_objects[tag]->move(pos);
}

void Allegro::removeGameObject(int tag)
{
    this->_objects.erase(tag);
}

void Allegro::removeGameObjects()
{
    if (this->_objects.size() > 0) {
        this->_objects.clear();
    }
}

void Allegro::displayText(const std::string &text,
const std::string &font, std::pair<int, int>  pos, size_t size)
{
    size_t index = 0;

    while (index < this->fonts.size()){
        if (fonts[index].path == font && (size_t)(fonts[index].size) == size)
            break;
        index++;
    }
    if (this->fonts.size() == 0 || index == this->fonts.size()) {
        AllegroFont newfont;
        newfont.path = font;
        newfont.size = size;
        newfont.font = al_load_ttf_font(font.c_str(), size, 0);
        this->fonts.push_back(newfont);
    }
    al_draw_text(this->fonts[index].font,
        al_map_rgba(255, 255, 255, 255), pos
    .first, pos
    .second, 0, text.c_str());
}

bool Allegro::isKeyPressed(Key key)
{
    int allegrokey;

    switch (key) {
        case ECHAP:
            allegrokey = ALLEGRO_KEY_ESCAPE;
            break;
        case A:
            allegrokey = ALLEGRO_KEY_A;
            break;
        case B:
            allegrokey = ALLEGRO_KEY_B;
            break;
        case C:
            allegrokey = ALLEGRO_KEY_C;
            break;
        case E:
            allegrokey = ALLEGRO_KEY_E;
            break;
        case F:
            allegrokey = ALLEGRO_KEY_F;
            break;
        case G:
            allegrokey = ALLEGRO_KEY_G;
            break;
        case H:
            allegrokey = ALLEGRO_KEY_H;
            break;
        case I:
            allegrokey = ALLEGRO_KEY_I;
            break;
        case J:
            allegrokey = ALLEGRO_KEY_J;
            break;
        case K:
            allegrokey = ALLEGRO_KEY_K;
            break;
        case L:
            allegrokey = ALLEGRO_KEY_L;
            break;
        case M:
            allegrokey = ALLEGRO_KEY_M;
            break;
        case N:
            allegrokey = ALLEGRO_KEY_N;
            break;
        case O:
            allegrokey = ALLEGRO_KEY_O;
            break;
        case P:
            allegrokey = ALLEGRO_KEY_P;
            break;
        case T:
            allegrokey = ALLEGRO_KEY_T;
            break;
        case U:
            allegrokey = ALLEGRO_KEY_U;
            break;
        case V:
            allegrokey = ALLEGRO_KEY_V;
            break;
        case W:
            allegrokey = ALLEGRO_KEY_W;
            break;
        case X:
            allegrokey = ALLEGRO_KEY_X;
            break;
        case Y:
            allegrokey = ALLEGRO_KEY_Y;
            break;
        case Z:
            allegrokey = ALLEGRO_KEY_Z;
            break;
        case S:
            allegrokey = ALLEGRO_KEY_S;
            break;
        case Q:
            allegrokey = ALLEGRO_KEY_Q;
            break;
        case D:
            allegrokey = ALLEGRO_KEY_D;
            break;
        case F1:
            allegrokey = ALLEGRO_KEY_F1;
            break;
        case ESP:
            allegrokey = ALLEGRO_KEY_SPACE;
            break;
        case R:
            allegrokey = ALLEGRO_KEY_R;
            break;
        case LEFT:
            allegrokey = ALLEGRO_KEY_LEFT;
            break;
        case RIGHT:
            allegrokey = ALLEGRO_KEY_RIGHT;
            break;
        case UP:
            allegrokey = ALLEGRO_KEY_UP;
            break;
        case DOWN:
            allegrokey = ALLEGRO_KEY_DOWN;
            break;
        case RETOUR:
            allegrokey = ALLEGRO_KEY_BACKSPACE;
            break;
        case ENTER:
            allegrokey = ALLEGRO_KEY_ENTER;
            break;
        default:
            allegrokey = -1;
            break;
    }
    if (keyreleased == false) {
        if (key != lastkey && al_key_down(&this->_key, allegrokey)) {
            lastkey = key;
            keyreleased = true;
            return (true);
        }
    }
    return (false);
}

bool Allegro::isWindowOpen()
{
    ALLEGRO_EVENT event;
    al_get_keyboard_state(&this->_key);

    if (al_get_next_event(this->_queue, &event)) {
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            return (false);
        if (event.type == ALLEGRO_EVENT_KEY_UP) {
            lastkey = Key::NONE;
            keyreleased = true;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
            keyreleased = false;
    }
    return (true);
}

void Allegro::clearWindow()
{
    al_clear_to_color(al_map_rgba(0, 0, 0, 255));
}

void Allegro::displayWindow()
{
    al_flip_display();
}

extern "C" std::shared_ptr<IGraphic> entry()
{
    return std::make_shared<Allegro>();
}