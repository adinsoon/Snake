#include "SFMLController.h"
#include "TextView.h"
#include <chrono>
#include <thread>
#include "PostGame.h"

SFMLController::SFMLController(Stats &s1, Board &b1, Manager &mgr1, Logic &l1, Tools &t1, Controller &c1, Menu &m1, SFMLView &v1, Highscore &s)
                                : stats(s1), board(b1), mgr(mgr1), logic(l1), tools(t1), ctrl(c1), menu(m1) , view(v1), score(s){
    // GameWindow.setVerticalSyncEnabled(true); //or
    // GameWindow.setFramerateLimit(30);
    int a = rand()%2;
    int b = rand()%2;
    if(a==0)
        haps.loadFromFile("..\\sounds\\haps.ogg");
    if(a==1)
        haps.loadFromFile("..\\sounds\\coin.ogg");
    if(b==0)
        loss.loadFromFile("..\\sounds\\lose.ogg");
    if(b==1)
        loss.loadFromFile("..\\sounds\\error.ogg");
    win.loadFromFile("..\\sounds\\win.ogg");
    start.loadFromFile("..\\sounds\\start.ogg");
    up.loadFromFile("..\\sounds\\up.ogg");
    myFont.loadFromFile("..\\font\\arial.ttf");
}

void SFMLController::play() {
    timers.gameSec=0;
    timers.gameMin=0;
    PostGame breakdown(stats,board,mgr,score);
    if(menu.getGameMode() == 0) game = "SNAKE - CREATIVE MODE";
    else if(menu.getGameMode() == 1) game = "SNAKE - BASIC MODE";
    constexpr int scr_height = 595;
    constexpr int scr_width = 525;
    ////// TIME
    std::string gameSec;
    std::string gameMin;
    sf::Clock clock;
    int seconds=0;
    int minutes=0;
    ///// POINTS
    std::string gamePoints;
    std::string gameRemain;
    //////
    bool playmusic = false;
    bool showresult = false;
    int pre,post;
    //////
    displayStats();
    sf::RenderWindow GameWindow(sf::VideoMode(scr_width, scr_height), game);
    while (GameWindow.isOpen()) {
        ////////// FINISHED GAME
        sf::Event event{};
        if (logic.getGameState() == WIN || logic.getGameState() == LOSS) {
            stats.setGameMinutes(minutes);
            stats.setGameSeconds(seconds);
            stats.setRemaining(board.getSnakeLimit() - board.getSnakeSize());
            if(!playmusic){
                if(logic.getGameState() == LOSS) sound.setBuffer(loss);
                else if(logic.getGameState() == WIN) sound.setBuffer(win);
                sound.play();
                playmusic = true;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if(!showresult) {
                ////////// RESULTS
                ///// WIN
                if (logic.getGameState() == WIN) {
                    breakdown.drawPostGame(1);
                }
                ///// LOSS
                else if (logic.getGameState() == LOSS) {
                    breakdown.drawPostGame(0);
                }
                GameWindow.close();
                showresult = true;
            }
            while (GameWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    exit(0);
            }
        }
        ////////// RUNNING GAME
        else {
            ////// TIME
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timers.timeMovement += time;
            timers.timeSpawnFruit += time;
            timers.timeSpawnObstacles += time;
            timers.gameSec += time;
            timers.gameMin += time;
            ////////     CLOCK
            seconds = static_cast<int>(timers.gameSec);
            minutes = static_cast<int>(timers.gameMin / 60);
            if (seconds == 60) timers.gameSec = 0;
            gameSec = std::to_string(seconds);
            gameMin = std::to_string(minutes);
            counter[0].setString(gameMin);
            counter[2].setString(gameSec);
            ////////////////////
            displayStats();
            pre = stats.getTotalFoodEaten();
            while (GameWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    GameWindow.close();
                    mgr.setGame(0);
                }
                else if (event.type == sf::Event::KeyPressed &&
                         ((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::W))) {
                    ctrl.move('w');
                    // tools.getGameInfo(); // diagnostic tool
                } else if (event.type == sf::Event::KeyPressed &&
                           ((event.key.code == sf::Keyboard::Down) || (event.key.code == sf::Keyboard::S))) {
                    ctrl.move('s');
                } else if (event.type == sf::Event::KeyPressed &&
                           ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::A))) {
                    ctrl.move('a');
                } else if (event.type == sf::Event::KeyPressed &&
                           ((event.key.code == sf::Keyboard::Right) || (event.key.code == sf::Keyboard::D))) {
                    ctrl.move('d');
                }
            }
            ////////// POINTS
            gamePoints = std::to_string(stats.getTotalPoints());
            points.setString(gamePoints);
            ////////// REMAINING
            gameRemain = std::to_string(board.getSnakeLimit() - board.getSnakeSize());
            remain.setString(gameRemain);
            /////////
            GameWindow.clear(sf::Color::Blue);
            view.drawBoard(GameWindow);
            GameWindow.draw(counter[0]);
            GameWindow.draw(counter[1]);
            GameWindow.draw(counter[2]);
            GameWindow.draw(points);
            GameWindow.draw(remain);
            GameWindow.display();
            moveCtrl(); // delay move
            spawnCtrl();    // check if fruits or obstacles are needed to re-spawn/de-spawn
            post = stats.getTotalFoodEaten();
            ///// play eating sound
            if (pre < post) {
                sound.setBuffer(haps);
                sound.play();
            }
            UP();
        }
    }
}

void SFMLController::spawnCtrl() {
    if(menu.getGameMode() == 0) {
        // if MODE == CREATIVE
        if (timers.timeSpawnObstacles > timers.delayObsResp) {
            timers.timeSpawnObstacles = 0;
            tools.despawnOldest("obstacle");
        }
        else if (stats.getObstacleCountOnB() < ctrl.getObsAllowed())
            tools.randomSpawn("obstacle");
    }
    if(timers.timeSpawnFruit>timers.delayFruitResp) {
        // fruit will de-spawn and re-spawn on different location if snake will not eat this fruit for too long
        timers.timeSpawnFruit = 0;
        tools.despawnOldest("fruit");
        // penalty for not eating on time
        stats.setPointsRate(stats.getPointsRate()-upgrade*10);
    }
    else if(stats.getFruitCountOnB()<ctrl.getFruAllowed()){
        timers.timeSpawnFruit=0;
        tools.randomSpawn("fruit");
        tools.despawnThat("fruit");
    }
}

void SFMLController::moveCtrl() {
    // snake will move if player will stay idle for too long
    if (timers.timeMovement > timers.delayMovement) {
        timers.timeMovement = 0;
        ctrl.delayMove();
    }
}

void SFMLController::displayStats() {
    ///// display time, points and remaining fruits to eat
    for(int i=0;i<3;i++){
        counter[i].setFont(myFont);
        counter[i].setFillColor(sf::Color::Black);
        counter[i].setCharacterSize(15);
    }
    counter[1].setCharacterSize(17);
    counter[1].setString(":");
    counter[0].setPosition(150,42);
    counter[1].setPosition(159,39);
    counter[2].setPosition(165,42);
    points.setFont(myFont);
    points.setFillColor(sf::Color::Black);
    points.setCharacterSize(15);
    points.setPosition(265,42);
    remain.setFont(myFont);
    remain.setFillColor(sf::Color::Black);
    remain.setCharacterSize(15);
    remain.setPosition(410,42);
}

void SFMLController::UP() {
    // every 10 fruits snake will move faster and gain more points for each fruit
    if (board.getSnakeSize()==10*upgrade){
        sound.setBuffer(up);
        sound.play();
        upgrade++;
        timers.delayMovement -= 0.01;
        stats.setPointsRate(stats.getPointsRate()+30);
    }
}


