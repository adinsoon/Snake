#ifndef SNAKEOLD_MENU_H
#define SNAKEOLD_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Highscore.h"

enum GameMode {CREATIVE,BASIC};

class Menu {
    Highscore &score;
    ///// MAIN MENU
    sf::Texture mainMenu;
    sf::Texture playButtonON;
    sf::Texture playButtonOFF;
    sf::Texture hscoresButtonON;
    sf::Texture hscoresButtonOFF;
    ///// RETURN BUTTON
    sf::Texture returnOFF;
    sf::Texture returnON;
    ///// GAME MODES
    sf::Texture basic;
    sf::Texture creative;
    ///// CHOOSE
    sf::Texture choosefruit;
    sf::Texture choosefence;
    sf::Texture chooseobst;
    ///// PLAY
    sf::Texture clean;
    sf::Texture snakeOFF;
    sf::Texture snakeON;
    GameMode mode;
    ///// SPRITES
    sf::Sprite sprites[10];
    sf::Sprite play[2];
    sf::Sprite choices[3];
    sf::Sprite snakes[2];
    sf::Sprite icons[3];
    ///// SKINS CHOOSEN
    std::string fruitSkin;
    std::string fenceSkin;
    std::string obstacleSkin;
    ////// SKINS PACK
    sf::Texture fruits[10];
    sf::Texture fences[10];
    sf::Texture obstacles[10];
    sf::Sprite items[10];
    ////// HIGHSCORES
    sf::Texture medals[3];
    sf::Texture ranking;
    sf::Sprite showhighscores[4];
    std::string point[10];
    sf::Text points[10];
    std::string timemin[10];
    sf::Text timemins[10];
    std::string timesec[10];
    sf::Text timesecs[10];
    std::string snake[10];
    sf::Text snakesize[10];
    sf::Text infos[4];
    sf::Text places[7];
    sf::Texture browseOFF;
    sf::Texture browseON;
    sf::Texture browseOFF2;
    sf::Texture browseON2;
    sf::Sprite browser[2];
    ///// AUDIO & TEXT
    sf::SoundBuffer click;
    sf::Sound sound;
    sf::Font font;
    sf::Text texts[10];
    void setSkin(std::string what, std::string which);
    void format();
public:
    Menu(Highscore &s);
    void showMenu();
    ////////// RETURNING SECTION
    std::string getFruitSkin() const;
    std::string getFenceSkin() const;
    std::string getObstacleSkin() const;
    GameMode getGameMode() const;
};


#endif //SNAKEOLD_MENU_H
