#ifndef SNAKEOLD_CONTROLLER_H
#define SNAKEOLD_CONTROLLER_H
#include "Board.h"
#include "Stats.h"
#include "GameLogic.h"
#include "Tools.h"

enum GameMode {BASIC, CREATIVE};

class Controller {
    Stats &stats;
    Board &board;
    GameLogic &logic;
    Tools &tools;
    GameMode mode;
public:
    Controller(Stats &s1, Board &b1, GameLogic &l1, Tools &t1, GameMode m);
    void move(char dir);
    void delayMove();
    void play();
};


#endif //SNAKEOLD_CONTROLLER_H
