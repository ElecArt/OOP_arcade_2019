/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
**        ${Description}
*/

#include "Pacman.hpp"

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

std::vector<std::string> Map = {
	"   111111111111111111111   ",
	"   100000000010000000001   ",
	"   101110111010111011101   ",
	"   1X1 101 10101 101 1X1   ",
	"   101110111010111011101   ",
	"   100000000000000000001   ",
	"   101110101111101011101   ",
	"   101110101111101011101   ",
	"   100000100010001000001   ",
	"   111110111 1 111011111   ",
	"       101       101       ",
	"       101 11 11 101       ",
	"   1111101 1G G1 1011111   ",
	"   1    0  1G G1  0    1   ",
	"   1111101 11111 1011111   ",
	"       101       101       ",
	"       101 11111 101       ",
	"   1111101 11111 1011111   ",
	"   100000000010000000001   ",
	"   101110111010111011101   ",
	"   1X00100000 00000100X1   ",
	"   111010101111101010111   ",
	"   111010101111101010111   ",
	"   100000100010001000001   ",
	"   101111111010111111101   ",
	"   100000000000000000001   ",
	"   111111111111111111111   "
};

Pacman::Pacman()
{
	this->_windowopen = true;
	this->_score = 0;
	_player.first = 13;
    _player.second = 20;
	_ghost1.first = 13;
	_ghost1.second = 12;
	_ghost2.first = 13;
	_ghost2.second = 14;
	_ghost3.first = 12;
	_ghost3.second = 12;
	_ghost4.first = 12;
	_ghost4.second = 14;
	_food.first = 20;
    _food.second = 20;
	srand(time(0));
	std::cout << "Game : Constructor of game!" << std::endl;
}

void Pacman::start(std::shared_ptr<IGraphic> graphic)
{
    std::cout << "Game : start" << std::endl;
    this->_graphic = graphic;
    this->_gameover = false;
    this->_graphic->removeGameObjects();
    graphic->loadGameObject(0, "games/pacman/images/wall", {80, 70});
    graphic->loadGameObject(1, "games/pacman/images/little_candy", {10, 10});
	graphic->loadGameObject(2, "games/pacman/images/big_candy", {10, 10});
	graphic->loadGameObject(3, "games/pacman/images/pacman", {50, 50});
	graphic->loadGameObject(7, "games/pacman/images/ghost", {50, 50});
	graphic->loadGameObject(8, "games/pacman/images/ghost", {50, 50});
	graphic->loadGameObject(9, "games/pacman/images/ghost", {50, 50});
	graphic->loadGameObject(10, "games/pacman/images/ghost", {50, 50});
    this->_start = std::chrono::steady_clock::now();
}

void Pacman::win()
{
    while (this->_windowopen == true) {
		if ((this->_windowopen = _graphic->isWindowOpen()) == false)
            exit(0);
        this->_graphic->clearWindow();
        this->_graphic->displayText("You Win", "resources/pixel.ttf",
		{((WIDTH / 2) / 2), ((HEIGHT / 2) - 50)}, 120);
        _graphic->displayWindow();
    }
}

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

void Pacman::display()
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->displayTwo(c, i, j);
			this->displayThree(c, i, j);
		}
	}
}

void Pacman::displayTwo(char c, int i, int j)
{
	if (c == '1') {
		_graphic->setGameObject(0, {(60 / 2)  - (27 / 2)
		+ i, (40 / 2) - (28 / 2) + j});
		_graphic->displayGameObject(0);
	}
	if (c == '0') {
		_graphic->setGameObject(1, {(60 / 2)  - (27 / 2)
		+ i, (40 / 2) - (28 / 2) + j});
		_food.first = i;
		_food.second = j;
		if ((_player.first == _food.first) && (_player.second
		== _food.second)) {
			Map[this->_food.first][this->_food.second] = ' ';
			_score += 1;
		}
		_graphic->displayGameObject(1);
	}
}

void Pacman::displayThree(char c, int i, int j)
{
	if (c == 'X') {
		_graphic->setGameObject(2, {(60 / 2) - (27 / 2)
		+ i, (40 / 2) - (28 / 2) + j});
		_food.first = i;
		_food.second = j;
		if ((_player.first == _food.first) &&
		(_player.second == _food.second)) {
			Map[this->_food.first][this->_food.second] = ' ';
			_score += 1;
		}
		_graphic->displayGameObject(2);
	}
}

void Pacman::player()
{
	this->_graphic->setGameObject(3, {(60 / 2)  - (27 / 2)
	+ _player.first, (40 / 2) - (28 / 2) + _player.second}, "");
	this->_graphic->displayGameObject(3);

}

void Pacman::move_player()
{
	direction == 0 ? _player.second += 1 : 0;
	direction == 1 ? _player.first -= 1 : 0;
	direction == 2 ? _player.first += 1 : 0;
	direction == 3 ? _player.second -= 1 : 0;
}

void Pacman::player_collision(std::vector<std::string> Map)
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->_pos.first = i;
			this->_pos.second = j;
			this->check_player_collision(c);
		}
	}
}

void Pacman::check_player_collision(char c)
{
	if (c == '1') {
		if (direction == 1 && _player.first == this->_pos.first
		&& _player.second == this->_pos.second)
			_player.first += 1;
		else if (direction == 3 && _player.first ==
		this->_pos.first && _player.second == this->_pos.second)
			_player.second += 1;
		else if (direction == 0 && _player.first ==
		this->_pos.first && _player.second == this->_pos.second)
			_player.second -= 1;
			else if (direction == 2 && _player.first == 
		this->_pos.first && _player.second == this->_pos.second)
			_player.first -= 1;					
	}
}

void Pacman::display_ghosts()
{
	this->_graphic->setGameObject(7, {(60 / 2)  - (27 / 2)
	+ _ghost1.first, (40 / 2) - (28 / 2) + _ghost1.second}, "");
	this->_graphic->displayGameObject(7);
	this->_graphic->setGameObject(8, {(60 / 2)  - (27 / 2)
	+ _ghost2.first, (40 / 2) - (28 / 2) + _ghost2.second}, "");
	this->_graphic->displayGameObject(8);
	this->_graphic->setGameObject(9, {(60 / 2)  - (27 / 2)
	+ _ghost3.first, (40 / 2) - (28 / 2) + _ghost3.second}, "");
	this->_graphic->displayGameObject(9);
	this->_graphic->setGameObject(10, {(60 / 2)  - (27 / 2)
	+ _ghost4.first, (40 / 2) - (28 / 2) + _ghost4.second}, "");
	this->_graphic->displayGameObject(10);
}

void Pacman::ghost_AI_compute_1(int n)
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->_pos.first = i;
			this->_pos.second = j;
			this->ghost_AI_compute_1_next(n, c);
		}
	}
}

void Pacman::ghost_AI_compute_1_next(int n, char c)
{
	if (c == '1') {
		if (n == 1 && _ghost1.first == this->_pos.first
		&& _ghost1.second == this->_pos.second) {
			_ghost1.first += 1;
		} else if (n == 3 && _ghost1.first == this->_pos.first
		&& _ghost1.second == this->_pos.second) {
			_ghost1.second += 1;
		} else if (n == 0 && _ghost1.first == this->_pos.first
		&& _ghost1.second == this->_pos.second) {
			_ghost1.second -= 1;
		} else if (n == 2 && _ghost1.first == this->_pos.first
		&& _ghost1.second == this->_pos.second) {
			_ghost1.first -= 1;			
		}
	}
}

void Pacman::ghost_AI_compute_2(int n)
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->_pos.first = i;
			this->_pos.second = j;
			this->ghost_AI_compute_2_next(n, c);
		}
	}
}

void Pacman::ghost_AI_compute_2_next(int n, char c)
{
	if (c == '1') {
		if (n == 1 && _ghost2.first == this->_pos.first
		&& _ghost2.second == this->_pos.second) {
			_ghost2.first += 1;
		} else if (n == 3 && _ghost2.first == this->_pos.first
		&& _ghost2.second == this->_pos.second) {
			_ghost2.second += 1;
		} else if (n == 0 && _ghost2.first == this->_pos.first
		&& _ghost2.second == this->_pos.second) {
			_ghost2.second -= 1;
		} else if (n == 2 && _ghost2.first == this->_pos.first
		&& _ghost2.second == this->_pos.second) {
			_ghost2.first -= 1;			
		}
	}
}

void Pacman::ghost_AI_compute_3(int n)
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->_pos.first = i;
			this->_pos.second = j;
			this->ghost_AI_compute_3_next(n, c);
		}
	}
}

void Pacman::ghost_AI_compute_3_next(int n, char c)
{
	if (c == '1') {
		if (n == 1 && _ghost3.first == this->_pos.first
		&& _ghost3.second == this->_pos.second) {
			_ghost3.first += 1;
		} else if (n == 3 && _ghost3.first ==
		this->_pos.first && _ghost3.second ==
		this->_pos.second) {
			_ghost3.second += 1;
		} else if (n == 0 && _ghost3.first ==
		this->_pos.first && _ghost3.second ==
		this->_pos.second) {
			_ghost3.second -= 1;
		} else if (n == 2 && _ghost3.first ==
		this->_pos.first && _ghost3.second ==
		this->_pos.second) {
			_ghost3.first -= 1;			
		}
	}
}

void Pacman::ghost_AI_compute_4(int n)
{
	char c;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			c = Map[i][j];
			this->_pos.first = i;
			this->_pos.second = j;
			this->ghost_AI_compute_4_next(n, c);
		}
	}
}

void Pacman::ghost_AI_compute_4_next(int n, char c)
{
	if (c == '1') {
		if (n == 1 && _ghost4.first == this->_pos.first &&
		_ghost4.second == this->_pos.second)
			_ghost4.first += 1;
		else if (n == 3 && _ghost4.first == this->_pos.first
		&& _ghost4.second == this->_pos.second)
			_ghost4.second += 1;
		else if (n == 0 && _ghost4.first == this->_pos.first
		&& _ghost4.second == this->_pos.second)
			_ghost4.second -= 1;
		else if (n == 2 && _ghost4.first == this->_pos.first
		&& _ghost4.second == this->_pos.second)
			_ghost4.first -= 1;
	}
}

void Pacman::AI_core_1()
{
	this->a = rand() % 4;

	this->a == 0 ? _ghost1.second += 1 : 0;
	this->a == 1 ? _ghost1.first -= 1 : 0;
	this->a == 2 ? _ghost1.first += 1 : 0;
	this->a == 3 ? _ghost1.second -= 1 : 0;
}

void Pacman::AI_core_2()
{
	this->b = rand() % 4;

	this->b == 0 ? _ghost2.second += 1 : 0;
	this->b == 1 ? _ghost2.first -= 1 : 0;
	this->b == 2 ? _ghost2.first += 1 : 0;
	this->b == 3 ? _ghost2.second -= 1 : 0;
}

void Pacman::AI_core_3()
{
	this->c = rand() % 4;

	this->c == 0 ? _ghost3.second += 1 : 0;
	this->c == 1 ? _ghost3.first -= 1 : 0;
	this->c == 2 ? _ghost3.first += 1 : 0;
	this->c == 3 ? _ghost3.second -= 1 : 0;
}

void Pacman::AI_core_4()
{
	this->d = rand() % 4;

	this->d == 0 ? _ghost4.second += 1 : 0;
	this->d == 1 ? _ghost4.first -= 1 : 0;
	this->d == 2 ? _ghost4.first += 1 : 0;
	this->d == 3 ? _ghost4.second -= 1 : 0;
}

void Pacman::check_death()
{
	if (_player.first == _ghost1.first &&
	_player.second == _ghost1.second)
        this->_gameover = true;
	if (_player.first == _ghost2.first &&
	_player.second == _ghost2.second)
        this->_gameover = true;
	if (_player.first == _ghost3.first &&
	_player.second == _ghost3.second)
        this->_gameover = true;
	if (_player.first == _ghost4.first &&
	_player.second == _ghost4.second)
        this->_gameover = true;
}

void Pacman::resume()
{
    this->_current = std::chrono::steady_clock::now();
	this->_graphic->isKeyPressed(Key::Q) ? direction = 1 : 0;
	this->_graphic->isKeyPressed(Key::D) ? direction = 2 : 0;
	this->_graphic->isKeyPressed(Key::Z) ? direction = 3 : 0;
	this->_graphic->isKeyPressed(Key::S) ? direction = 0 : 0;
	if (std::chrono::duration_cast<std::chrono::milliseconds>
	(this->_current - this->_start).count() > speed) {
        this->_start = std::chrono::steady_clock::now();
		if (_score == 192) {
			std::cout << "You Win" << std::endl;
			win();
		}
		this->compute();
	}
	display();
	player();
	display_ghosts();
}

void Pacman::compute()
{
	AI_core_1();
	AI_core_2();
	AI_core_3();
	AI_core_4();
	move_player();
	ghost_AI_compute_1(a);
	ghost_AI_compute_2(b);
	ghost_AI_compute_3(c);
	ghost_AI_compute_4(d);
	player_collision(Map);
	check_death();
}

int Pacman::getScore() const
{
	return (this->_score);
}

extern "C" std::shared_ptr<IGame> entry()
{
    return std::make_shared<Pacman>();
}