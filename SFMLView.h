#ifndef SNAKEOLD_SFMLVIEW_H
#define SNAKEOLD_SFMLVIEW_H
#include "Board.h"
#include "Tools.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <string>

class SFMLView {
    Board &board;
    Tools &tools;
    Menu &menu;
    std::string fen;
    std::string fru;
    std::string obs;
    ///// SNAKE
    sf::Texture headUP;
    sf::Texture headLEFT;
    sf::Texture headDOWN;
    sf::Texture headRIGHT;
    sf::Texture torso;
    ///// items
    sf::Texture wall;
    sf::Texture obstacle;
    sf::Texture blanko;
    sf::Texture fruit;
    //////////
    sf::Texture upperbar;
    sf::Sprite bar;
    sf::Sprite pieces;
    const int cell = 21;
public:
    SFMLView(Board &b1, Tools &t1, Menu &m1);
    void drawBoard(sf::RenderWindow &w1);
};


#endif //SNAKEOLD_SFMLVIEW_H
