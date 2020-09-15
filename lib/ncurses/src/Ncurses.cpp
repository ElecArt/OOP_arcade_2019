/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

Ncurses::Ncurses()
{
}

void Ncurses::openWindow(std::size_t height,
std::size_t width, const std::string &name)
{
    (void)width;
    (void)height;
    (void)name;
	raw();
	this->_window = initscr();
	noecho();
	cbreak();
	set_escdelay(1);
	start_color();
	curs_set(false);
    nodelay(this->_window, true);
	keypad(this->_window, true);
}

void Ncurses::closeWindow()
{
	endwin();
}

void Ncurses::loadGameObject(int tag,
const std::string &sprite_path, std::pair<int, int> pos)
{
    std::shared_ptr<GameObject> object =
    std::make_shared<GameObject>(sprite_path + ".txt", pos);
    this->_objects.insert(std::pair<int,
    std::shared_ptr<GameObject>>(tag, object));
}

void Ncurses::displayGameObject(int tag)
{
    mvprintw(this->_objects[tag]->getPos().second,
    this->_objects[tag]->getPos().first, "%c",
    this->_objects[tag]->getSprite());
}

void Ncurses::setGameObject(int tag,
std::pair<int, int> pos, const std::string &sprite_path)
{
    (void)sprite_path;
    this->_objects[tag]->move(pos);
}

void Ncurses::removeGameObject(int tag)
{
    this->_objects.erase(tag);
}

void Ncurses::removeGameObjects()
{
    this->_objects.clear();
}

void Ncurses::displayText(const std::string &text,
const std::string &font, std::pair<int, int>  pos, size_t size)
{
    (void)font;
    (void)size;
    mvprintw(pos.second, pos.first, "%s", text.c_str());
}

bool Ncurses::isKeyPressed(Key key)
{
	int ncurseskey = -1;

    switch (key) {
        case ECHAP:
            ncurseskey = 27;
            break;
        case F1:
            ncurseskey = KEY_F(1);
            break;
        case A:
            ncurseskey = 'A';
            break;
        case B:
            ncurseskey = 'B';
            break;
        case C:
            ncurseskey = 'C';
            break;
        case E:
            ncurseskey = 'E';
            break;
        case F:
            ncurseskey = 'F';
            break;
        case G:
            ncurseskey = 'G';
            break;
        case H:
            ncurseskey = 'H';
            break;
        case I:
            ncurseskey = 'I';
            break;
        case J:
            ncurseskey = 'J';
            break;
        case K:
            ncurseskey = 'K';
            break;
        case L:
            ncurseskey = 'L';
            break;
        case M:
            ncurseskey = 'M';
            break;
        case N:
            ncurseskey = 'N';
            break;
        case O:
            ncurseskey = 'O';
            break;
        case P:
            ncurseskey = 'P';
            break;
        case T:
            ncurseskey = 'T';
            break;
        case U:
            ncurseskey = 'U';
            break;
        case V:
            ncurseskey = 'V';
            break;
        case W:
            ncurseskey = 'W';
            break;
        case X:
            ncurseskey = 'X';
            break;
        case Y:
            ncurseskey = 'Y';
            break;
        case Z:
            ncurseskey = 122;
            break;
        case S:
            ncurseskey = 115;
            break;
        case Q:
            ncurseskey = 113;
            break;
        case D:
            ncurseskey = 100;
            break;
        case ESP:
            ncurseskey = 32;
            break;
        case R:
            ncurseskey = 114;
            break;
        case LEFT:
            ncurseskey = KEY_LEFT;
            break;
        case RIGHT:
            ncurseskey = KEY_RIGHT;
            break;
        case UP:
            ncurseskey = KEY_UP;
            break;
        case DOWN:
            ncurseskey = KEY_DOWN;
            break;
        case RETOUR:
            ncurseskey = KEY_BACKSPACE;
            break;
        case ENTER:
            ncurseskey = KEY_ENTER;
            break;
        default:
            ncurseskey = -1;
    }
    if (this->_char == ncurseskey)
        return (true);
    else
        return (false);
}

bool Ncurses::isWindowOpen()
{
    if (this->_char == 32)
        return (false);
    else
        return (true);
}

void Ncurses::clearWindow()
{
    this->_char = getch();
	clear();
}

void Ncurses::displayWindow()
{
	refresh();
}

extern "C" std::shared_ptr<IGraphic> entry()
{
    return std::make_shared<Ncurses>();
}