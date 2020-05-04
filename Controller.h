#ifndef SNAKEOLD_CONTROLLER_H
#define SNAKEOLD_CONTROLLER_H
#include "Board.h"
#include "Stats.h"
#include "Logic.h"
#include "Tools.h"
#include "Menu.h"
#include <string>

class Controller {
    Stats &stats;
    Board &board;
    Logic &logic;
    Tools &tools;
    GameMode mode;
    int fruitsAmount;
    int obstaclesAmount;
public:
    Controller(Stats &s1, Board &b1, Logic &l1, Tools &t1, GameMode m, int fruAm=5, int obsAm=10);
    void move(char dir);
    void delayMove();

    int getFruAllowed() const;
    int getObsAllowed() const;
    GameMode getGameMode() const;
};


#endif //SNAKEOLD_CONTROLLER_H
