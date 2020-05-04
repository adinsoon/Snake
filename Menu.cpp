#include "Menu.h"
#include <iostream>

Menu::Menu() {
    ////// MAIN MENU
    mainMenu.loadFromFile("..\\icons\\menu\\Menu.png");
    playButtonOFF.loadFromFile("..\\icons\\menu\\playOFF.png");
    playButtonON.loadFromFile("..\\icons\\menu\\playON.png");
    hscoresButtonOFF.loadFromFile("..\\icons\\menu\\scoresOFF.png");
    hscoresButtonON.loadFromFile("..\\icons\\menu\\scoresON.png");
    ////// RETURN BUTTON
    returnOFF.loadFromFile("..\\icons\\menu\\returnOFF.png");
    returnON.loadFromFile("..\\icons\\menu\\returnON.png");
    ////// GAME MODES
    basic.loadFromFile("..\\icons\\menu\\basic.png");
    creative.loadFromFile("..\\icons\\menu\\creative.png");
    ////// CHOOSE
    choosefruit.loadFromFile("..\\icons\\menu\\choosefruit.png");
    choosefence.loadFromFile("..\\icons\\menu\\choosefence.png");
    chooseobst.loadFromFile("..\\icons\\menu\\choosetrap.png");
    ////// PLAY
    clean.loadFromFile("..\\icons\\menu\\clean.png");
    snakeOFF.loadFromFile("..\\icons\\menu\\snakeOFF.png");
    snakeON.loadFromFile("..\\icons\\menu\\snakeON.png");
    ////// AUDIO & TEXT
    click.loadFromFile("..\\sounds\\click.ogg");
    font.loadFromFile("..\\font\\arial.ttf");
    ///// SKINS packs
    /// fruits
    fruits[0].loadFromFile("..\\icons\\menu\\applemenu.png");
    fruits[1].loadFromFile("..\\icons\\menu\\moneymenu.png");
    fruits[2].loadFromFile("..\\icons\\menu\\wingmenu.png");
    /// fences
    fences[0].loadFromFile("..\\icons\\fence\\red_wall.png");
    fences[1].loadFromFile("..\\icons\\fence\\orange_wall.png");
    fences[2].loadFromFile("..\\icons\\fence\\yellow_wall.png");
    fences[3].loadFromFile("..\\icons\\fence\\green_wall.png");
    fences[4].loadFromFile("..\\icons\\fence\\mint_wall.png");
    fences[5].loadFromFile("..\\icons\\fence\\blue_wall.png");
    fences[6].loadFromFile("..\\icons\\fence\\dark_wall.png");
    fences[7].loadFromFile("..\\icons\\fence\\pink_wall.png");
    /// obstacles
    obstacles[0].loadFromFile("..\\icons\\menu\\bushmenu.png");
    obstacles[1].loadFromFile("..\\icons\\menu\\sianomenu.png");
    obstacles[2].loadFromFile("..\\icons\\menu\\lakemenu.png");
    ////// SKINS - default choice
    fruitSkin = "apple";
    fenceSkin = "red wall";
    obstacleSkin = "bush";
}

void Menu::showMenu() {
    constexpr int scr_height = 230;
    constexpr int scr_width = 460;
    int menu = 1;  ////// 1 - DEFAULT, 2 - MODES, 3 - CREATIVE, 4 - BASIC, 5 - CHOOSE FRUIT, 6 - CHOOSE FENCES, 7 - CHOOSE OBSTACLE
    ////// AFTER CHOOSING SKINS (OR DEFAULT) CLICKING ON HIGHLIGHTED SNAKE WILL START THE GAME
    sf::RenderWindow MenuWin(sf::VideoMode(scr_width, scr_height), "Snake Menu");
    while (MenuWin.isOpen()) {
        sf::Event e;
        while (MenuWin.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                MenuWin.close();
                exit(0);
            }
            //////////     MAIN MENU
            else if (menu == 1) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(MenuWin);
                        //////////  PLAY BUTTON
                        if (play[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 2;
                        }
                        //////////  HIGHSCORES
                        if (sprites[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                            std::cout << "ranking";
                        }
                    }
                }
            }
            //////////     GAME MODES
            else if (menu == 2) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        ////////// BASIC
                        if (sprites[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 4;
                        }
                            ////////// CREATIVE
                        else if (sprites[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 3;
                        }
                            ////////// RETURN BUTTON
                        else if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 1;
                        }
                    }
                }
            }
            ////////// CREATIVE PRESSED
            else if (menu == 3) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        ////////// FRUIT SKIN
                        if (choices[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 5;
                            mode = CREATIVE;

                        }
                        ////////// FENCES SKIN
                        else if (choices[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 6;
                            mode = CREATIVE;

                        }
                        ////////// OBSTACLES SKIN
                        else if (choices[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 7;
                            mode = CREATIVE;

                        }
                        ////////// RETURN BUTTON
                        else if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 2;
                        }
                        ////////// SNAKE PRESSED - PLAY
                        else if (snakes[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            mode = CREATIVE;
                            MenuWin.close();
                        }
                    }
                }
            }
            ////////// BASIC PRESSED
            else if (menu == 4) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        ////////// FRUIT SKIN
                        if (choices[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 5;
                            mode = BASIC;
                        }
                        ////////// FENCES SKIN
                        else if (choices[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 6;
                            mode = BASIC;
                        }
                        ////////// RETURN BUTTON
                        else if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            menu = 2;
                        }
                        ////////// SNAKE PRESSED - PLAY
                        else if (snakes[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            MenuWin.close();
                            mode = BASIC;
                        }
                    }
                }
            }
            ////// FRUITS
            else if (menu == 5) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        if (items[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fruitSkin = "apple";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fruitSkin = "coin";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fruitSkin = "wing" ;
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                    }
                }
            }
            ////// FENCES
            else if(menu==6) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        if (items[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "red wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "orange wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "yellow wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[3].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "green wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "mint wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[5].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "blue wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[6].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "dark wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[7].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            fenceSkin = "pink wall";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                    }
                }
            }
            ////// OBSTACLES
            else if(menu == 7){
                if (e.type == sf::Event::MouseButtonPressed) {
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(MenuWin);
                        if (items[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            obstacleSkin = "bush";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            obstacleSkin = "haystack";
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                        if (items[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_position))) {
                            sound.setBuffer(click);
                            sound.play();
                            obstacleSkin = "lake" ;
                            if (mode == CREATIVE) {
                                menu = 3;
                            } else if (mode == BASIC) {
                                menu = 4;
                            }
                        }
                    }
                }
            }
        }
        MenuWin.clear(sf::Color::Black);
        //////     MAIN MENU
        if (menu == 1) {
            MenuWin.clear(sf::Color::Black);
            sprites[3].setTexture(mainMenu);
            MenuWin.draw(sprites[3]);
            /////     BUTTONS
            play[1].setTexture(playButtonOFF);
            play[1].setPosition(210, 50);
            sprites[2].setTexture(hscoresButtonOFF);
            sprites[2].setPosition(210, 160);
            MenuWin.draw(play[1]);
            MenuWin.draw(sprites[2]);
            /////     INTERACTIVE MAIN BUTTON
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(MenuWin);
            if (play[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                play[1].setTexture(playButtonON);
                MenuWin.draw(play[1]);
            }   ///////     PLAY
            if (sprites[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                sprites[2].setTexture(hscoresButtonON);
                MenuWin.draw(sprites[2]);
            }   //////     HIGHSCORES
            MenuWin.display();
        }
        //////     INTERACTIVE GAME MODES
        if (menu == 2) {
            MenuWin.clear(sf::Color::Black);
            MenuWin.draw(sprites[3]);
            sprites[1].setTexture(basic);
            sprites[1].setTextureRect(sf::IntRect(0, 0, 200, 43));
            sprites[1].setPosition(210, 100);
            sprites[2].setTexture(creative);
            sprites[2].setTextureRect(sf::IntRect(0, 0, 200, 43));
            sprites[2].setPosition(210, 160);
            sprites[4].setScale(0.5, 0.5);
            sprites[4].setTexture(returnOFF);
            sprites[4].setPosition(380, 20);
            MenuWin.draw(sprites[1]);
            MenuWin.draw(sprites[2]);
            MenuWin.draw(sprites[4]);
            sf::Vector2i mouse_poss = sf::Mouse::getPosition(MenuWin);
            //////     BASIC
            if (sprites[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                sprites[1].setTextureRect(sf::IntRect(0, 43, 200, 43));
                MenuWin.draw(sprites[1]);
            } /////     CREATIVE
            if (sprites[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                sprites[2].setTextureRect(sf::IntRect(0, 43, 200, 43));
                MenuWin.draw(sprites[2]);
            } /////     RETURN BUTTON
            if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                sprites[4].setTexture(returnON);
                MenuWin.draw(sprites[4]);
            }
            MenuWin.display();
        }
        //////     CREATIVE MODE OPTIONS
        if (menu == 3) {
            MenuWin.clear(sf::Color::Black);
            snakes[0].setTexture(clean);
            snakes[1].setTexture(snakeOFF);
            MenuWin.draw(snakes[0]);
            choices[0].setTexture(choosefruit);
            choices[0].setTextureRect(sf::IntRect(0, 0, 200, 43));
            choices[0].setPosition(190, 70);
            choices[1].setTexture(choosefence);
            choices[1].setTextureRect(sf::IntRect(0, 0, 200, 43));
            choices[1].setPosition(190, 120);
            choices[2].setTexture(chooseobst);
            choices[2].setTextureRect(sf::IntRect(0, 0, 200, 43));
            choices[2].setPosition(190, 170);
            MenuWin.draw(choices[0]);
            MenuWin.draw(choices[1]);
            MenuWin.draw(choices[2]);
            MenuWin.draw(snakes[1]);
            sprites[4].setTexture(returnOFF);
            sprites[4].setPosition(380, 20);
            MenuWin.draw(sprites[4]);
            setSkin("fruit", fruitSkin);
            setSkin("fence", fenceSkin);
            setSkin("obstacle", obstacleSkin);
            icons[0].setPosition(400, 70);
            icons[1].setPosition(400, 120);
            icons[2].setPosition(400, 170);
            MenuWin.draw(icons[0]);
            MenuWin.draw(icons[1]);
            MenuWin.draw(icons[2]);
            sf::Vector2i mouse_poss = sf::Mouse::getPosition(MenuWin);
            //////     CHOOSE FRUIT
            if (choices[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                choices[0].setTextureRect(sf::IntRect(1, 42, 200, 42));
                MenuWin.draw(choices[0]);
            } /////      CHOOSE FENCE
            if (choices[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                choices[1].setTextureRect(sf::IntRect(1, 42, 200, 42));
                MenuWin.draw(choices[1]);
            } /////     CHOOSE OBSTACLE
            if (choices[2].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                choices[2].setTextureRect(sf::IntRect(1, 42, 200, 42));
                MenuWin.draw(choices[2]);
            } //////     RETURN BUTTON
            if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                sprites[4].setTexture(returnON);
                MenuWin.draw(sprites[4]);
            } //////      PLAY SNAKE BUTTON
            if (snakes[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                snakes[1].setTexture(snakeON);
                MenuWin.draw(snakes[1]);
            }
            MenuWin.display();
        }
        //////      BASIC MODE OPTIONS
        if (menu == 4) {
            MenuWin.clear(sf::Color::Black);
            snakes[0].setTexture(clean);
            snakes[1].setTexture(snakeOFF);
            MenuWin.draw(snakes[0]);
            choices[0].setTexture(choosefruit);
            choices[0].setTextureRect(sf::IntRect(0, 0, 200, 43));
            choices[0].setPosition(190, 90);
            choices[1].setTexture(choosefence);
            choices[1].setTextureRect(sf::IntRect(0, 0, 200, 43));
            choices[1].setPosition(190, 140);
            MenuWin.draw(choices[0]);
            MenuWin.draw(choices[1]);
            MenuWin.draw(snakes[1]);
            sprites[4].setTexture(returnOFF);
            sprites[4].setPosition(380, 20);
            MenuWin.draw(sprites[4]);
            ////// SKINS - default option
            setSkin("fruit", fruitSkin);
            setSkin("fence", fenceSkin);
            icons[0].setPosition(400, 90);
            icons[1].setPosition(400, 140);
            MenuWin.draw(icons[0]);
            MenuWin.draw(icons[1]);
            sf::Vector2i mouse_poss = sf::Mouse::getPosition(MenuWin);
            //////      CHOOSE FRUIT
            if (choices[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                choices[0].setTextureRect(sf::IntRect(1, 42, 200, 42));
                MenuWin.draw(choices[0]);
            } //////     CHOOSE FENCE
            if (choices[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                choices[1].setTextureRect(sf::IntRect(1, 42, 200, 42));
                MenuWin.draw(choices[1]);
            } //////     RETURN BUTTON
            if (sprites[4].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                sprites[4].setTexture(returnON);
                MenuWin.draw(sprites[4]);
            } //////     PLAY SNAKE  BUTTON
            if (snakes[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_poss))) {
                snakes[1].setTexture(snakeON);
                MenuWin.draw(snakes[1]);
            }
            MenuWin.display();
        }
        //////     CHOOSE FRUIT
        if (menu == 5) {
            MenuWin.clear(sf::Color::Black);
            sprites[3].setTexture(mainMenu);
            MenuWin.draw(sprites[3]);
            for (int i = 0; i < 3; i++) {
                items[i].setTexture(fruits[i]);
                items[i].setScale(0.6, 0.6);
                items[i].setPosition(220 + i * 80, 100);
                MenuWin.draw(items[i]);
            }
            MenuWin.display();
        }
        ////// CHOOSE FENCE
        if (menu == 6) {
            MenuWin.clear(sf::Color::Black);
            sprites[3].setTexture(mainMenu);
            MenuWin.draw(sprites[3]);
            for (int i = 0; i < 8; i++) {
                items[i].setTexture(fences[i]);
                items[i].setScale(0.6, 0.6);
            }
            for (int h = 0; h < 3; h++) {
                items[h].setPosition(230 + h * 80, 40);
                MenuWin.draw(items[h]);
            }
            for (int j = 3; j < 6; j++) {
                items[j].setPosition(230 + (j-3) * 80, 100);
                MenuWin.draw(items[j]);
            }
            for (int k = 6; k < 8; k++) {
                items[k].setPosition(230 + (k-6) * 80, 160);
                MenuWin.draw(items[k]);
            }
            MenuWin.display();
        }
        ////// CHOOSE OBSTACLE
        if(menu==7){
            MenuWin.clear(sf::Color::Black);
            sprites[3].setTexture(mainMenu);
            MenuWin.draw(sprites[3]);
            for (int i = 0; i < 3; i++) {
                items[i].setTexture(obstacles[i]);
                items[i].setScale(0.6, 0.6);
                items[i].setPosition(220 + i * 80, 100);
                MenuWin.draw(items[i]);
            }
            MenuWin.display();
        }
    }
}

void Menu::setSkin(std::string what , std::string which) {
    if(what == "fruit") {
        if (which == "apple") {
            icons[0].setTexture(fruits[0]);
        }
        else if(which == "coin"){
            icons[0].setTexture(fruits[1]);
        }
        else if(which == "wing"){
            icons[0].setTexture(fruits[2]);
        }
        icons[0].setScale(0.6,0.6);
    }
    if(what == "fence"){
        if(which == "red wall") {
            icons[1].setTexture(fences[0]);
        }
        else if(which == "orange wall") {
            icons[1].setTexture(fences[1]);
        }
        else if(which == "yellow wall"){
            icons[1].setTexture(fences[2]);
        }
        else if(which == "green wall"){
            icons[1].setTexture(fences[3]);
        }
        else if(which == "mint wall"){
            icons[1].setTexture(fences[4]);
        }
        else if(which == "blue wall"){
            icons[1].setTexture(fences[5]);
        }
        else if(which == "dark wall"){
            icons[1].setTexture(fences[6]);
        }
        else if(which == "pink wall"){
            icons[1].setTexture(fences[7]);
        }
        icons[1].setScale(0.6,0.6);
    }
    else if(what == "obstacle") {
        if(which == "bush") {
            icons[2].setTexture(obstacles[0]);
        }
        else if(which == "haystack"){
            icons[2].setTexture(obstacles[1]);
        }
        else if(which == "lake"){
            icons[2].setTexture(obstacles[2]);
        }
        icons[2].setScale(0.6,0.6);
    }
}

std::string Menu::getFruitSkin() const {
    return fruitSkin;
}

std::string Menu::getFenceSkin() const {
    return fenceSkin;
}

std::string Menu::getObstacleSkin() const {
    return obstacleSkin;
}

GameMode Menu::getGameMode() const {
    return mode;
}
