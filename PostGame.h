#ifndef SNAKEOLD_POSTGAME_H
#define SNAKEOLD_POSTGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Stats.h"
#include "Board.h"
#include "Manager.h"
#include "Highscore.h"

class PostGame {
    Stats &stats;
    Board &board;
    Manager &manage;
    Highscore &sc;

    sf::Texture win;
    sf::Texture loss;
    sf::Texture again;
    sf::Texture menu;
    sf::Sprite button[2];
    sf::Sprite background;
    sf::SoundBuffer tick;
    sf::Sound click;
    std::string title;
    sf::Text result;
    //////
    sf::Font myFont;
    //////
    sf::Text time[4];
    std::string times[2];
    /////
    sf::Text point[2];
    std::string points;
    //////
    sf::Text size[2];
    std::string sizee;
    /////
    sf::Text fruit[6];
    std::string fruits[3];
    void format();
    int fsize=16;
public:
    PostGame(Stats &s1, Board &b1, Manager &man1, Highscore &ss);
    void drawPostGame(int n);
};


#endif //SNAKEOLD_POSTGAME_H
