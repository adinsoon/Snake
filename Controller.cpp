#include "Controller.h"

Controller::Controller(Stats &s1, Board &b1, Logic &l1, Tools &t1, GameMode m, int fruAm, int obsAm)
                    : stats(s1), board(b1), logic(l1), tools(t1), mode(m), fruitsAmount(fruAm), obstaclesAmount(obsAm) {
    if(mode == BASIC){
        tools.fenceFill();
        fruitsAmount = 1;
        obstaclesAmount = 0;
        tools.randomSpawn("fruit");
    }
    if(mode == CREATIVE){
        tools.fenceFill();
        for(int i=0;i<fruitsAmount;i++)
            tools.randomSpawn("fruit");
        for(int i=0;i<obstaclesAmount;i++)
            tools.randomSpawn("obstacle");
    }
}

////////////////////////////////////////////////

int Controller::getFruAllowed() const {
    return fruitsAmount;
}

int Controller::getObsAllowed() const {
    return obstaclesAmount;
}

GameMode Controller::getGameMode() const {
    return mode;
}

////////////////////////////////////////////////

void Controller::move(char dir) {
    if(!logic.isRunning()){}
    else
        board.turn(dir);
}

void Controller::delayMove() {
    if(board.getTurn() == "UP")
        move('w');
    else if(board.getTurn() == "DOWN")
        move('s');
    else if(board.getTurn() == "LEFT")
        move('a');
    else if(board.getTurn() == "RIGHT")
        move('d');
}
