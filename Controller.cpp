#include "Controller.h"

Controller::Controller(Stats &s1, Board &b1, GameLogic &l1, Tools &t1, GameMode m) : stats(s1), board(b1), logic(l1), tools(t1), mode(m) {
    if(mode == BASIC){
        board.toggleWH(false);
        tools.fenceFill();
        tools.randomSpawn("fruit");
        tools.randomSpawn("obstacle");
    }
    if(mode == CREATIVE){
        board.toggleWH(true);
    }
}

void Controller::move(char dir) {
    if(!logic.isRunning()){}
    else
        board.turn(dir);
}

void Controller::play() {

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
