#ifndef SNAKEOLD_LOGIC_H
#define SNAKEOLD_LOGIC_H
#include "Board.h"

enum GameState {RUNNING, WIN, LOSS};

class Logic {
    Board &board;
    GameState state;
public:
    Logic(Board &b1);
    GameState getGameState() const;
    bool isRunning() const;
};


#endif //SNAKEOLD_LOGIC_H
