#include <ctime>
#include "Board.h"

Board::Board(int h, int w, int limit, Stats &s) : stats(s){
    height = h;
    width = w;
    snakeLimit = limit;
    for(int row=0;row<100;row++){
        snake[row].x = 0;
        snake[row].y = 0;
        for(int col=0;col<100;col++){
            board[row][col].hasTorso = false;
            board[row][col].hasHead = false;
            board[row][col].hasFence = false;
            board[row][col].hasFruit = false;
            board[row][col].hasObstacle = false;
        }
    }
    snake[0].x = height/2;
    snake[0].y = snake[1].y = (width/2);
    snake[1].x = snake[0].x+1;
    board[snake[0].x][snake[0].y].hasHead = true;
}

int Board::getBoardHeight() const {
    return height;
}

int Board::getBoardWidth() const {
    return width;
}

int Board::getSnakeLimit() const {
    return snakeLimit;
}

int Board::getSnakeSize() const {
    return snakeSize;
}

bool Board::isOnBoard(int row, int col) const {
    return row>=0 && col>=0 && row<=height && col<=width;
}

bool Board::hasFence(int row, int col) const {
    return board[row][col].hasFence;
}

bool Board::isHead(int row, int col) const {
    return board[row][col].hasHead;
}

bool Board::isTorso(int row, int col) const {
    return board[row][col].hasTorso;
}

bool Board::hasSnake(int row, int col) const {
    return isHead(row, col) || isTorso(row, col);
}

bool Board::hasFruit(int row, int col) const {
    return board[row][col].hasFruit;
}

bool Board::hasObstacle(int row, int col) const {
    return board[row][col].hasObstacle;
}

// return TRUE if if any of there is TRUE
bool Board::isAny(int row, int col) const {
    if(isOnBoard(row,col))
        return (hasSnake(row,col) || hasFruit(row,col) || hasFence(row,col) || hasObstacle(row,col));
    return false;
}

bool Board::isEaten() const {
    return (!isHead(snake[0].x,snake[0].y) && hasFruit(snake[0].x,snake[0].y));
}

bool Board::isHit() const {
    for (int i = 1; i < snakeSize; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    if (hasObstacle(snake[0].x,snake[0].y))
        return true;
    else if (hasFence(snake[0].x,snake[0].y))
        return true;
    return false;
}

void Board::setFence(int row, int col, bool fence) {
    board[row][col].hasFence = fence;
}

void Board::setFruit(int row, int col, bool fruit) {
    board[row][col].hasFruit = fruit;
}

void Board::setObstacle(int row, int col, bool obstacle) {
    board[row][col].hasObstacle = obstacle;
}

void Board::growSnake(bool grow) {
    if(grow) snakeSize++;
    else snakeSize--;
}

void Board::update() {
    board[snake[0].x][snake[0].y].hasHead = !board[snake[0].x][snake[0].y].hasHead;
    int size = snakeSize-1;
    for(int i=1;i<=size;i++)
        board[snake[i].x][snake[i].y].hasTorso = !board[snake[i].x][snake[i].y].hasTorso;
}

void Board::turn(char dir) {
    if (((dir == 'W' || dir == 'w') && (getTurn() == "DOWN"))       // checking illegal moves
        || ((dir == 'S' || dir == 's') && (getTurn() == "UP"))
        || ((dir == 'A' || dir == 'a') && (getTurn() == "RIGHT"))
        || ((dir == 'D' || dir == 'd') && (getTurn() == "LEFT"))) {}
    else {
        update();
//        if(WH) {
//            if (snake[0].x >= height)
//                snake[0].x = 0;
//            else if (snake[0].y >= width)
//                snake[0].y = 0;
//            else if (snake[0].x <= 0)
//                snake[0].x = height;
//            else if (snake[0].y <= 0)
//                snake[0].y = width;
//        }
        for (int i=snakeSize;i>0; i--) {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }
        if (dir == 'W' || dir == 'w') {
            if (direction == "UP" || direction == "LEFT" || direction == "RIGHT") {
                snake[0].x -= 1;
                direction = "UP";
            }
        }
        else if (dir == 'S' || dir == 's') {
            if (direction == "DOWN" || direction == "LEFT" || direction == "RIGHT") {
                snake[0].x += 1;
                direction = "DOWN";
            }
        }
        else if (dir == 'A' || dir == 'a') {
            if (direction == "UP" || direction == "DOWN" || direction == "LEFT") {
                snake[0].y -= 1;
                direction = "LEFT";
            }
        }
        else if (dir == 'D' || dir == 'd') {
            if (direction == "UP" || direction == "DOWN" || direction == "RIGHT") {
                snake[0].y += 1;
                direction = "RIGHT";
            }
        }
        eatFruit();
        update();
    }
}

std::string Board::getTurn() const {
    return direction;
}

void Board::eatFruit() {
    if(isEaten()) {
        setFruit(snake[0].x, snake[0].y, false);
        growSnake(true);
        stats.countPoints(true);
        stats.countFruit(false);
        stats.countUnEaten(false);
        stats.countFoodEaten(true);
    }
}

void Board::toggleWH(bool toggle) {
    WH = toggle;
}

bool Board::isSnakeOut() const{
    return !isOnBoard(snake[0].x, snake[0].y);
}

bool Board::isHeadAround(int row, int col) const {
    for(int i=-3;i<4;i++){
        for(int j=-3;j<4;j++){
            if(isHead(row+i,col+j))
                return true;
        }
    }
    return false;
}

void Board::clearSnake() {
    for(int i=0;i<snakeSize;i++){
        snake[i].x = 0;
        snake[i].y = 0;
    }
    for(int i=0;i<height;i++){
        for(int j=0;i<width;j++){
            board[i][j].hasHead = false;
            board[i][j].hasTorso = false;
        }
    }
}
