/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoreState
*/

#include "ScoreState.hpp"
#include <fstream>
#include <sstream>

#define HEIGHT 40 * 20
#define WIDTH 60 * 20

ScoreState::ScoreState(StateMachine &machine,
std::shared_ptr<IGraphic> lib_graphic, bool replace) :
State{machine, lib_graphic, replace}
{
    std::cout << "ScoreState : ctor" << std::endl;
    machine.statetype = 1;
    this->_lib_graphic->loadGameObject(-7, "resources/background_game",{0, 0});
    std::ifstream score("./score.ini");
    //int j = m_machine._lib_game->getScore();
    //std::cout << "machine score " << j << std::endl;
    for (std::string line; getline(score, line);) {
        if (line.size() > 0) {
            std::vector<std::string> splitted = split(line, '=');
            _playername = splitted[0];
            _score = splitted[1];
            playerscore.first = _playername;
            playerscore.second = std::stoi(_score);
            update_score.push_back(playerscore);
            /*field.insert(std::pair<std::string, int>
            (splitted[0], std::stoi(splitted[1])));*/
        }
    }
    this->_windowopen = true;
}

std::vector<std::string> ScoreState::split
(const std::string &s, char separator)
{
    std::vector<std::string> result;
    std::stringstream stream(s);
    std::string item;

    while (getline(stream, item, separator))
        result.push_back(item);
    return (result);
}

ScoreState::~ScoreState()
{
    std::cout << "ScoreState : dtor" << std::endl;
}

void ScoreState::pause()
{
    std::cout << "ScoreState Pause" << std::endl;
}

void ScoreState::update()
{
    if ((this->_windowopen = _lib_graphic->isWindowOpen()) == false)
        m_machine.quit();
    if (this->_lib_graphic->isKeyPressed(Key::ECHAP))
        m_next = StateMachine::build<MenuState>(
        m_machine, this->_lib_graphic, true);
    if (this->_lib_graphic->isKeyPressed(Key::ESP))
        m_next = StateMachine::build<MenuState>(
        m_machine, this->_lib_graphic, true);
}

void ScoreState::resume()
{
    std::cout << "ScoreState Resume" << std::endl;
}

bool sortp(const std::pair<std::string, int>& i, const std::pair<std::string, int>& j)
{ 
	return (i.second > j.second); 
}

void ScoreState::draw()
{
    _lib_graphic->clearWindow();
    _lib_graphic->displayGameObject(-7);
    this->_lib_graphic->displayText("Scoreboard","resources/pixel.ttf",
        {(WIDTH /2) - ((60 * 10) / 2), (HEIGHT / 2) - (100 / 2) - 250 }, 100);
    int counter = 0;
    /*for (auto begin = field.begin(); begin != field.end();
    begin++, counter++) {
        std::stringstream text;
        text << begin->first << " - " + std::to_string(begin->second);
        this->_lib_graphic->displayText(text.str(),
        "resources/pixel.ttf", {(WIDTH / 2) - ((28 *
        text.str().length()) / 2),((HEIGHT / 2) - (48 / 2)) +
        (counter * 48) - 120}, 48);
    }*/

    for (int i = 0; i < update_score.size(); i++, counter++) {
        std::stringstream text;
        std::sort(update_score.begin(), update_score.end(), sortp);
        text <<  update_score[i].first << " - " + std::to_string(update_score[i].second);
        this->_lib_graphic->displayText(text.str(),
        "resources/pixel.ttf", {(WIDTH / 2) - ((28 *
        text.str().length()) / 2),((HEIGHT / 2) - (48 / 2)) +
        (counter * 48) - 120}, 48);
    }
    this->_lib_graphic->displayText("Press space to go back to menu.",
    "resources/pixel.ttf", {(WIDTH / 2) - ((14 * 31) / 2),((HEIGHT / 2)
    - (24 / 2) + 300)}, 24);
}