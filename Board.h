#ifndef SNAKEOLD_BOARD_H
#define SNAKEOLD_BOARD_H
#include <string>
#include <iostream>
#include "Stats.h"

struct Field {
    bool hasFence;
    bool hasHead;
    bool hasTorso;
    bool hasFruit;
    bool hasObstacle;
};

struct Snake {
    int x;
    int y;
};

class Board {
    Stats &stats;
    Field board[100][100];
    Snake snake[100];

    ///// board
    int height;
    int width;

    ///// initial field stats
    int snakeSize=1;
    int snakeLimit;

    ///// snake control
    std::string direction = "UP";
    void update();

    bool WH;
public:
    ///// constructor
    Board(int h, int w, int limit, Stats &s);

    ///// getters
    //----- board
    int getBoardHeight() const;
    int getBoardWidth() const;
    //----- snake
    int getSnakeLimit() const;
    int getSnakeSize() const;

    ///// booleans /////
    //----- validation checker
    bool isOnBoard(int row, int col) const;
    bool isAny(int row, int col) const;
    //----- snake
    bool isHead(int row, int col) const;
    bool isTorso(int row, int col) const;
    bool hasSnake(int row, int col) const;
    //----- things on board
    bool hasFence(int row, int col) const;
    bool hasFruit(int row, int col) const;
    bool hasObstacle(int row, int col) const;
    //----- collision
    bool isEaten() const;
    bool isHit() const;

    ///// set on fixed cords
    void setFence(int row, int col, bool fence);
    void setFruit(int row, int col, bool fruit);
    void setObstacle(int row, int col, bool obstacle);

    ///// increase snake size
    void growSnake(bool grow);
    void eatFruit();

    ///// snake control
    void toggleWH(bool toggle);
    void turn(char dir);
    std::string getTurn() const;
    void autoMove();

};


#endif //SNAKEOLD_BOARD_H
