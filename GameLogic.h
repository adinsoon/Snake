#ifndef SNAKEOLD_GAMELOGIC_H
#define SNAKEOLD_GAMELOGIC_H
#include "Board.h"

enum GameState {RUNNING, WIN, LOSS};

class GameLogic {
    Board &board;
    GameState state;
public:
    GameLogic(Board &b1);
    GameState getGameState() const;
    bool isRunning() const;
};


#endif //SNAKEOLD_GAMELOGIC_H
