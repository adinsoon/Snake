#include "Logic.h"

Logic::Logic(Board &b1) : board(b1) {

}

GameState Logic::getGameState() const {
    if(board.isHit())
        return LOSS;
    else if(board.isSnakeOut())
        return LOSS;
    else if(board.getSnakeSize() == board.getSnakeLimit())
        return WIN;
    else
        return RUNNING;
}

bool Logic::isRunning() const {
    return (getGameState() == RUNNING);
}


