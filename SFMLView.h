#ifndef SNAKEOLD_SFMLVIEW_H
#define SNAKEOLD_SFMLVIEW_H
#include "Board.h"
#include "Tools.h"
#include <SFML/Graphics.hpp>

class SFMLView {
    Board &board;
    Tools &tools;
    sf::Texture wall;
    sf::Texture obstacle;
    sf::Texture blanko;
    sf::Texture headUP;
    sf::Texture headLEFT;
    sf::Texture headDOWN;
    sf::Texture headRIGHT;
    sf::Texture torso;
    sf::Texture fruit;
    sf::Sprite pieces;
    const int cell = 21;
public:
    SFMLView(Board &b1, Tools &t1);
    void drawBoard(sf::RenderWindow &w1);
};


#endif //SNAKEOLD_SFMLVIEW_H
