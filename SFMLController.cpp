#include "SFMLController.h"
#include "TextView.h"

SFMLController::SFMLController(Stats &s1, Board &b1, Tools &t1, Controller &c1, SFMLView &v1) : stats(s1), board(b1), tools(t1), ctrl(c1), view(v1){
    // GameWindow.setVerticalSyncEnabled(true); //or
    // GameWindow.setFramerateLimit(30);
    haps.loadFromFile("..\\sounds\\haps.ogg");

}

void SFMLController::play() {
    int scr_height = board.getBoardHeight() * cell;
    int scr_width = board.getBoardWidth() * cell;
    sf::Clock clock;
    float timer=0;
    float delay=0.15;
    eat.setBuffer(haps);
    int pre,post;
    sf::RenderWindow GameWindow(sf::VideoMode(scr_width, scr_height), "Snake Game");
    while (GameWindow.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        sf::Event event{};
        pre = stats.getFoodEaten();
        while (GameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                GameWindow.close();
            else if (event.type == sf::Event::KeyPressed &&
                     ((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::W))) {
                ctrl.move('w');
                tools.getGameInfo();
            }
            else if (event.type == sf::Event::KeyPressed &&
                     ((event.key.code == sf::Keyboard::Down) || (event.key.code == sf::Keyboard::S))) {
                ctrl.move('s');
            }
            else if (event.type == sf::Event::KeyPressed &&
                     ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::A))) {
                ctrl.move('a');
            }
            else if (event.type == sf::Event::KeyPressed &&
                     ((event.key.code == sf::Keyboard::Right) || (event.key.code == sf::Keyboard::D))) {
                ctrl.move('d');
            }
        }
        GameWindow.clear(sf::Color::Blue);
        if(timer>delay){
            timer=0;
            ctrl.delayMove();
        }
        post=stats.getFoodEaten();
        if(pre<post)
            eat.play();
        if(stats.getFruitCount() == 0)
            tools.randomSpawn("fruit");
        view.drawBoard(GameWindow);
        GameWindow.display();
    }
}
