#include "PostGame.h"

PostGame::PostGame(Stats &s1, Board &b1, Manager &man1, Highscore &ss) : stats(s1), board(b1), manage(man1), sc(ss) {
    win.loadFromFile("..\\icons\\result\\win.png");
    loss.loadFromFile("..\\icons\\result\\lose.png");
    again.loadFromFile("..\\icons\\result\\again.png");
    menu.loadFromFile("..\\icons\\result\\menu.png");
    tick.loadFromFile("..\\sounds\\click.ogg");
    myFont.loadFromFile("..\\font\\arial.ttf");
}

void PostGame::drawPostGame(int n) {
    format();
    sc.saveScores(points,times[0],times[1],sizee);
    if (n == 1) { //WIN
        title = "WIN!";
        result.setString("COOL!");
        background.setTexture(win);
    } else if (n == 0) { //LOSE
        title = "LOSS!";
        result.setString("OUCH!");
        background.setTexture(loss);
    }
    constexpr int height = 240;
    constexpr int width = 425;
    sf::RenderWindow PostGame(sf::VideoMode(width, height), title);
    while (PostGame.isOpen()) {
        sf::Event e;
        while (PostGame.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                PostGame.close();
                exit(0);
            }
            else if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(PostGame);
                    //////////  PLAY BUTTON
                    if (button[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                        click.setBuffer(tick);
                        click.play();
                        manage.setGame(2);
                        PostGame.close();
                    }
                    //////////  GO MENU BUTTON
                    if (button[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
                        click.setBuffer(tick);
                        click.play();
                        manage.setGame(1);
                        PostGame.close();
                    }
                }
            }
        }
        PostGame.clear(sf::Color::Black);
        PostGame.draw(background);
        PostGame.draw(result);
        for(int i=0;i<4;i++)
            PostGame.draw(time[i]);
        for(int i=0;i<2;i++){
            PostGame.draw(point[i]);
            PostGame.draw(size[i]);
            button[i].setTextureRect(sf::IntRect(2,2,198,41));
            PostGame.draw(button[i]);
        }
        for(int i=0;i<6;i++){
            PostGame.draw(fruit[i]);
        }
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(PostGame);
        if (button[0].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
            button[0].setTextureRect(sf::IntRect(2,43,198,42));
            PostGame.draw(button[0]);
        }   ///////     PLAY
        if (button[1].getGlobalBounds().contains(static_cast <sf::Vector2f>(mouse_pos))) {
            button[1].setTextureRect(sf::IntRect(2,43,198,42));
            PostGame.draw(button[1]);
        }
        PostGame.display();
    }
}

void PostGame::format() {
    button[0].setTexture(again);
    button[1].setTexture(menu);
    times[0] = std::to_string(stats.getGameMinutes());
    times[1] = std::to_string(stats.getGameSeconds());
    //////
    time[0].setString(times[0]);    // mins
    time[1].setString(times[1]);    // secs
    time[2].setString("Time:");
    time[3].setString(":");
    //////
    points = std::to_string(stats.getTotalPoints());
    ///
    point[0].setString(points);     //total
    point[1].setString("Points:");
    sizee = std::to_string(board.getSnakeSize());
    ////
    size[0].setString(sizee);       //size
    size[1].setString("Snake Size:");
    fruits[0] = std::to_string(stats.getFruitsTotal());
    fruits[1] = std::to_string(stats.getTotalFoodEaten());
    fruits[2] = std::to_string(stats.getTotalUneaten());
    //////
    fruit[0].setString(fruits[0]);  //total
    fruit[1].setString(fruits[1]);  //eaten
    fruit[2].setString(fruits[2]);  //uneaten
    fruit[3].setString("Total fruits:");
    fruit[4].setString("Eaten:");
    fruit[5].setString("Missed:");
    //////
    result.setCharacterSize(25);
    result.setFillColor(sf::Color::Black);
    result.setOutlineColor(sf::Color::White);
    result.setFont(myFont);
    result.setPosition(240,10);
    //////
    for(int i=0;i<4;i++){
        time[i].setCharacterSize(fsize);
        time[i].setFillColor(sf::Color::Black);
        time[i].setFont(myFont);
    }
    time[2].setPosition(200,60);
    time[0].setPosition(300,60);
    time[3].setPosition(310,60);
    time[1].setPosition(315,60);
    for(int i=0;i<2;i++) {
        point[i].setCharacterSize(fsize);
        point[i].setFillColor(sf::Color::Black);
        point[i].setFont(myFont);
        size[i].setCharacterSize(fsize);
        size[i].setFillColor(sf::Color::Black);
        size[i].setFont(myFont);
        button[i].setScale(0.5,0.5);
        button[i].setPosition(190+i*120,210);
    }
    point[1].setPosition(200,80);
    point[0].setPosition(300,80);
    size[0].setPosition(300,100);
    size[1].setPosition(200,100);
    for(int i=0;i<6;i++){
        fruit[i].setCharacterSize(fsize);
        fruit[i].setFont(myFont);
        fruit[i].setFillColor(sf::Color::Black);
    }
    fruit[3].setPosition(200,140);
    fruit[4].setPosition(200,160);
    fruit[5].setPosition(200,180);
    fruit[0].setPosition(300,140);
    fruit[1].setPosition(300,160);
    fruit[2].setPosition(300,180);
    ///////////////////////////////////////

}
