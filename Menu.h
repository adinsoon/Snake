#ifndef SNAKEOLD_MENU_H
#define SNAKEOLD_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

enum GameMode {CREATIVE,BASIC};

class Menu {
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
    ///// AUDIO & TEXT
    sf::SoundBuffer click;
    sf::Sound sound;
    sf::Font font;
    sf::Text texts[10];
    void setSkin(std::string what, std::string which);
public:
    Menu();
    void showMenu();
    ////////// RETURNING SECTION
    std::string getFruitSkin() const;
    std::string getFenceSkin() const;
    std::string getObstacleSkin() const;
    GameMode getGameMode() const;
};


#endif //SNAKEOLD_MENU_H
