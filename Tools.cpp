#include "Tools.h"
#include <ctime>

// ------------------------
void set_time(){
    srand(time(NULL));}
// ------------------------

Tools::Tools(Board &b1, Stats &s1, Logic &l1) : board(b1), stats(s1), logic(l1) {
    set_time();
}


void Tools::putFence(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setFence(row,col, true);
        stats.countFence(true);
        savePos("fence",row,col);
    }
    else {}
}

void Tools::putFruit(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setFruit(row,col, true);
        stats.countFruit(true);
        stats.countUnEaten(true);
        savePos("fruit",row,col);
    }
    else {}
}

void Tools::putObstacle(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setObstacle(row,col, true);
        stats.countObstacle(true);
        savePos("obstacle",row,col);
    }
    else {}
}

void Tools::takeFence(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setFence(row,col, false);
        stats.countFence(false);
    }
    else {}
}

void Tools::takeFruit(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setFruit(row,col, false);
        stats.countFruit(false);
    }
    else {}
}

void Tools::takeObstacle(int row, int col) {
    if(board.isOnBoard(row,col)) {
        board.setObstacle(row,col, false);
        stats.countObstacle(false);
    }
    else {}
}

void Tools::fenceFill() {
    for(int row=0;row<board.getBoardHeight();row++) {
        for (int col = 0; col < board.getBoardWidth(); col++) {
            if (row == 0 || col == 0 || row == board.getBoardHeight() - 1 || col == board.getBoardWidth() - 1)
                putFence(row,col);
        }
    }
}

void Tools::fixedSpawn(std::string what, int x, int y) {
    if((logic.getGameState() == WIN) || (logic.getGameState() == LOSS)) {}
    else {
        if (what == "fence") {
            if (!board.isAny(x, y))
                putFence(x, y);
        } else if (what == "fruit") {
            if (!board.isAny(x, y))
                putFruit(x, y);
        } else if (what == "obstacle") {
            if (!board.isAny(x, y))
                putObstacle(x, y);
        } else {}
    }
}

void Tools::randomSpawn(std::string what) {
    int spawn=1;
    for(int i=0;i<spawn;i++){
        int x_row = rand()%board.getBoardHeight();
        int y_col = rand()%board.getBoardWidth();
        if(board.isAny(x_row,y_col) || board.isHeadAround(x_row,y_col))     // anytime
            i--;
        else if(board.getTurn() == " "){        // start of the game
            if(board.isAny(x_row-1,y_col))
                i--;
        }
        else
            fixedSpawn(what,x_row,y_col);
    }
}

void Tools::savePos(std::string what, int x, int y) {
    container temp;
    temp.x = x;
    temp.y = y;
    if(what == "fence")
        fencesPos.push_back(temp);
    else if(what == "fruit")
        fruitsPos.push_back(temp);
    else if(what == "obstacle")
        obstaclesPos.push_back(temp);
}

void Tools::getGameInfo() const {
    std::cout << "[LOGIC/GAME] Game state: " << logic.getGameState() << std::endl;
    /////
    std::cout << "[BOARD/SIZE] Height of the board: " << board.getBoardHeight() << std::endl;
    std::cout << "[BOARD/SIZE] Width of the board: " << board.getBoardWidth() << std::endl;
    //////
    std::cout << "[BOARD/SNAKE] Snake size: " << board.getSnakeSize() << std::endl;
    std::cout << "[BOARD/SNAKE] limit: " << board.getSnakeLimit() << std::endl;
    std::cout << "[SNAKE/MOVE] Current turn: " << board.getTurn() << std::endl;
    /////
    std::cout << "[STATS] Current Fruits on Board:  " << stats.getFruitCountOnB() << std::endl;
    std::cout << "[STATS] Total Fruits during game: " << stats.getFruitsTotal() << std::endl;
    std::cout << "[STATS] Current Fences on Board: " << stats.getFenceCountOnB() << std::endl;
    std::cout << "[STATS] Total Fences during game: " << stats.getFencesTotal() << std::endl;
    std::cout << "[STATS] Current Obstacles on Board: " << stats.getObstacleCountOnB() << std::endl;
    std::cout << "[STATS] Total Obstacles during game: " << stats.getObstaclesTotal() << std::endl;
    /////
    std::cout << "[STATS] Total Fruits eaten during game:  " << stats.getPointsOnB() << std::endl;
    std::cout << "[STATS] Current uneaten food on Board: " << stats.getUnEatenOnB() << std::endl;
    std::cout << "[STATS] Total uneaten food during game:  " << stats.getTotalUneaten() << std::endl;
    std::cout << "[STATS] Total Points earned during game: " << stats.getTotalPoints() << std::endl;
    std::cout << std::endl;
    std::cout << "FRUITS:" << std::endl;
    for(int i=0;i<fruitsPos.size();i++){
        std::cout << "Nr [" << i+1 << "] x: " << fruitsPos[i].x << " y: " << fruitsPos[i].y << std::endl;
    }
    std::cout << std::endl;
}

void Tools::debug_display() const {
    for(int row=0;row<board.getBoardHeight();row++){
        for(int col=0;col<board.getBoardWidth();col++){
            if(board.hasFence(row,col))
                std::cout << "# ";  // fence
            else if(board.hasFruit(row,col))
                std::cout << "% ";   // fruit
            else if(board.hasObstacle(row,col))
                std::cout << "X ";   // obstacle
            else if(board.isHead(row,col))
                std::cout << "H ";   // head
            else if(board.isTorso(row,col))
                std::cout << "t ";   // torso
            else
                std::cout << "  ";  // blank space
        }
        std::cout << std::endl;
    }
}

char Tools::getFieldInfo(int row, int col) const {
    if (board.hasFence(row, col))
        return '#';
    else if (board.isHead(row, col)) {
        if (board.getTurn() == "UP")
            return '^';
        else if (board.getTurn() == "DOWN")
            return 'v';
        else if (board.getTurn() == "LEFT")
            return '<';
        else if (board.getTurn() == "RIGHT")
            return '>';
    }
    else if (board.isTorso(row, col))
        return '*';
    else if (board.hasFruit(row, col))
        return '%';
    else if (board.hasObstacle(row, col))
        return 'X';
    else
        return ' ';
    return{};
}

void Tools::despawnOldest(std::string what) {
    if(!logic.isRunning()) {}
    else {
        if (what == "fence") {
            takeFence(fencesPos[0].x,fencesPos[0].y);
            fencesPos.erase(fencesPos.begin());
        } else if (what == "fruit") {
            takeFruit(fruitsPos[0].x, fruitsPos[0].y);
            fruitsPos.erase(fruitsPos.begin());
        } else if (what == "obstacle") {
            takeObstacle(obstaclesPos[0].x,obstaclesPos[0].y);
            obstaclesPos.erase(obstaclesPos.begin());
        }
    }
}

void Tools::despawnThat(std::string what) {
    if(what == "fruit") {
        for (int i = 0; i < fruitsPos.size(); i++) {
            if (board.hasSnake(fruitsPos[i].x, fruitsPos[i].y)) {
                fruitsPos.erase(fruitsPos.begin() + i);
            }
        }
    }
}




