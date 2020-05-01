#ifndef SNAKEOLD_SFMLCONTROLLER_H
#define SNAKEOLD_SFMLCONTROLLER_H
#include "Board.h"
#include "Tools.h"
#include "Stats.h"
#include "Controller.h"
#include "SFMLView.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SFMLController {
    Stats &stats;
    Board &board;
    Tools &tools;
    Controller &ctrl;
    SFMLView &view;
    sf::SoundBuffer haps;
    sf::Sound eat;
    const int cell = 21;
public:
    SFMLController(Stats &s1, Board &b1, Tools &t1, Controller &c1, SFMLView &v1);
    void play();
};


#endif //SNAKEOLD_SFMLCONTROLLER_H
