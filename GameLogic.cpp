#include "GameLogic.h"

GameLogic::GameLogic(Board &b1) : board(b1) {

}

GameState GameLogic::getGameState() const {
    if(board.isHit())
        return LOSS;
    else if(board.getSnakeSize() == board.getSnakeLimit())
        return WIN;
    else
        return RUNNING;
}

bool GameLogic::isRunning() const {
    return (getGameState() == RUNNING);
}


